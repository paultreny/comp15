//  Paul Reny - COMP 15 - 07/24/11
//  HW3
//  AVLTree.h
//
//  Copyright 2011 Keith Noto. All rights reserved.
//

/*
 
 AVL tree inherits from BSTree (see BSTree.h), and overrides two functions
 (insert and delete) to rebalance the tree after any change.
 
 (It also uses AVLNode nodes instead of BSNodes, because AVLNode caches its height
 so it need not be recalculated all the time)
 
 
 */


#ifndef COMP15_AVL_TREE
#define COMP15_AVL_TREE 0

// shorthand for AVLNode pointer typecasts:  ANP( x ) means x is an 
// AVL Node Pointer using the key_t, data_t we always use.
#define ANP(_type_t) ((AVLNode<key_t,data_t>*)(_type_t))

#include "BSTree.h"
#include <stack> 	// for keeping track of which nodes need rebalancing

// The easiest way (not always the best way) to write template classes is to
// put everything in the header file.

namespace comp15 { // so that types and functions defined here are put in our special namespace
  
  template <typename key_t, typename data_t> class AVLTree; // prototype
  
  // A binary search tree Node for AVL trees
  template <typename key_t, typename data_t>
  class AVLNode : public BSNode<key_t,data_t> { 
    
    friend class AVLTree<key_t,data_t>; // AVLTree adjusts 'h'
    
  private:
    int h; // height=longest path to a leaf (redundant information cached for efficiency)
    
  public:
    
    // constructor
    AVLNode(const key_t &k, const data_t &d)  : BSNode<key_t,data_t>(k,d), h(0) { }
    
    // override BSNode<,>::height to work in O(1) time
    virtual int height() const { return h; }
    
    // compute balance factor
    int balance_factor() const { return   (this->left ? ANP(this->left)->h : -1) 
      - (this->right ? ANP(this->right)->h : -1); }
    
  };
  
  template <typename key_t, typename data_t>
  class AVLTree : public BSTree<key_t,data_t> { 
    
  protected:
    bool rebalance(AVLNode<key_t,data_t> **);	// check given pointer for rebalance requirement and rebalance (return true if any change is made)
    bool reset_height(AVLNode<key_t,data_t>*);		// reset height of given node based on children (return true if a change is made)
    void rotate_left(AVLNode<key_t,data_t> **pptr);	// rotate **pptr node left (and update *pptr)
    void rotate_right(AVLNode<key_t,data_t> **pptr);// rotate **pptr node right (and update *pptr)
    
  public:
    
    // Insert and rebalance
    virtual bool insert( const key_t &key, const data_t &data );
		
    // Remove and rebalance
    virtual bool remove( const key_t &key );
    
  };
  
  template <typename key_t, typename data_t>
  bool AVLTree<key_t,data_t>::insert(const key_t &key, const data_t &data) {
    
    bool ans = true; // was a node inserted?
    
    if (!this->root) { 
      
      // insert into empty tree is easy...
      this->root = new AVLNode<key_t,data_t>(key,data);  // insert, no rebalance required
      
    } else {
      
      std::stack<AVLNode<key_t,data_t>**> P; // stack of nodes in the search path that require height updates and rebalancing
      P.push((AVLNode<key_t,data_t>**)(&(this->root)));
      
      // find insert position
      for (AVLNode<key_t,data_t> *node = ANP(this->root); node!=NULL; ) { 
        
        if (key < node->key) {	// left subtree
          if (!node->left) { 
            node->left = new AVLNode<key_t,data_t>(key,data); 
            break; // done with insert
          } else {
            P.push((AVLNode<key_t,data_t>**)(&(node->left)));
            node = ANP(node->left);	// ANP = AVL Node Pointer
          }
          
        } else if ( node->key < key ) {	// right subtree
          if (!node->right) { 
            node->right = new AVLNode<key_t,data_t>(key,data); 
            break; // done with insert 
          } else { 
            P.push((AVLNode<key_t,data_t>**)(&(node->right)));
            node = ANP(node->right); 
          }
          
        } else {  // key == node->key (item is already in the tree!)
          ans = false;
          break;
          
        }
      }
      
      
      if (ans) { 	// we did an insert, so we have to rebalance
        while (!P.empty()) { 
          rebalance(P.top()); 
          P.pop();
        }
      }
      
    } // if nonempty tree
    
    return ans;
  }
  
  template <typename key_t, typename data_t>
  bool AVLTree<key_t,data_t>::remove(const key_t &key) { 
    
    // Keep track of potential rebalance nodes 
    std::stack< AVLNode<key_t,data_t>** > S1;	// on our way to finding the key node
    std::stack< AVLNode<key_t,data_t>** > S2;	// on our way to finding the replacement node 
    
    // start with address of root (may need to change what root is pointing to)
    AVLNode<key_t,data_t> **pptr = (AVLNode<key_t,data_t>**)(&(this->root));
    
    // search to find address of node with key
    while ( *pptr && (*pptr)->key != key  ) {
      
      S1.push(pptr);
      if ( key < (*pptr)->key ) { pptr = (AVLNode<key_t,data_t>**)(&((*pptr)->left)); }
      else                      { pptr = (AVLNode<key_t,data_t>**)(&((*pptr)->right)); }
      
    }
    
    if (*pptr) { // found node to delete
      
      AVLNode<key_t,data_t> *L = (AVLNode<key_t,data_t>*)((*pptr)->left);
      AVLNode<key_t,data_t> *R = (AVLNode<key_t,data_t>*)((*pptr)->right);
      
      delete *pptr; // delete what *pptr is pointing to 
      
      if (!L && !R) { // deleted a leaf
        *pptr = NULL; 
      } else if (!R) { // no right subtree anyway
        *pptr = L;  
      } else if (!L) { // no left subtree
        *pptr = R;  
      } else if (L && !(L -> right)) { // no right subtree on left
        L -> right = R;
        *pptr = L; // special case that makes general case below easier (now it can assume L has a valid right subtree)
        rebalance(pptr); // do need to readjust height of L, though
        
      } else { 
        
        // find a replacement value in the rightmost positoin of the left subtree
        
        AVLNode<key_t,data_t> **t = (AVLNode<key_t,data_t>**)(&(L->right));
        S2.push(t);
        while ( (*t) -> right ) { 
          t = (AVLNode<key_t,data_t>**)(&((*t)->right)); 
          S2.push(t);
        }
        
        *pptr = *t; 	// *t points to that rightmost node
        *t = (AVLNode<key_t,data_t>*)((*pptr) -> left); // put it's left subtree back in place
        (*pptr) -> left = L ; // finally set pptr's subtrees
        (*pptr) -> right = R ; 
        
        S2.push( (AVLNode<key_t,data_t>**)(&((*pptr)->left)) ); 
        S2.push( pptr );
        
        // rebalance bottom-up
        while (!S2.empty() && rebalance( S2.top() )) { S2.pop(); }
        
      }
      
      // rebalance bottom-up
      while (!S1.empty() && rebalance( S1.top() )) { S1.pop(); }
      
      return true;
      
    } // if key found (*pptr != NULL)
    return false; // no match
    
  }
  
  template <typename key_t, typename data_t>
  bool AVLTree<key_t,data_t>::reset_height(AVLNode<key_t,data_t> *P) { 
    
    assert(P);
    
    // reset h (height) of node
    int hL = (P->left)  ? ANP(P->left)->h + 1 : 0; // height via left
    int hR = (P->right) ? ((AVLNode<key_t,data_t>*)(P->right))->h + 1 : 0; 
    
    int old = P->h;
    P->h = (hL > hR) ? hL : hR; 
    return old != P->h;
    
  }
  
  template <typename key_t, typename data_t>
  bool AVLTree<key_t,data_t>::rebalance(AVLNode<key_t,data_t> **pptr) { 
    
    if (!(*pptr)) { return false; } // nothing to do 
    
    bool ans = reset_height(*pptr); 
    
    while ((*pptr)->balance_factor() < -1 || (*pptr)->balance_factor() > +1) { 
      
      if ( (*pptr)->balance_factor() == +2 && ANP((*pptr)->left)->balance_factor() < 0 ) { // left-right case
        rotate_left( (AVLNode<key_t,data_t>**)(&((*pptr)->left)) );
        ans = true;
        
      } else  if ( (*pptr)->balance_factor() == -2 && ANP((*pptr)->right)->balance_factor() > 0  ) { // right-left case
        rotate_right( (AVLNode<key_t,data_t>**)(&((*pptr)->right)) );
        ans = true;
      } 
      
      if ( (*pptr)->balance_factor() == +2 ) { // left-left case
        rotate_right( pptr );
        ans = true;
        
      } else if ( (*pptr)->balance_factor() == -2 ) { // right-right case
        rotate_left( pptr );
        ans = true;
        
      }
      
      if (ans) { ans = reset_height(*pptr); }
      
    }
    
    return ans;
    
  }
	
  template <typename key_t, typename data_t>
  void AVLTree<key_t,data_t>::rotate_left(AVLNode<key_t,data_t> **pptr) { 
    
    assert(*pptr);
    assert((*pptr)->right);
    
    AVLNode<key_t,data_t> *tmp = ANP((*pptr)->right);
    (*pptr) -> right = ANP(tmp->left);
    tmp->left = *pptr;
    *pptr = tmp;
    
    reset_height( ANP((*pptr)->left) );
    reset_height( *pptr );
  }
  
  template <typename key_t, typename data_t>
  void AVLTree<key_t,data_t>::rotate_right(AVLNode<key_t,data_t> **pptr) { 
    
    assert(*pptr);
    assert((*pptr)->left);
    
    AVLNode<key_t,data_t> *tmp = ANP((*pptr)->left);
    (*pptr) -> left = ANP(tmp->right);
    tmp->right = *pptr;
    *pptr = tmp;
    
    reset_height( ANP((*pptr)->right) );
    reset_height( *pptr );
  }
  
}//namespace
#endif

