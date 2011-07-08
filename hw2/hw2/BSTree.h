//  Paul Reny - COMP 15 - 07/07/11
//  HW2
//  BSTree.h
//
//  Copyright 2011 Keith Noto. All rights reserved.
//

/*
 
 Defines a template binary search tree (BSTree) made up of binary search nodes (BSNode).
 The nodes (and the tree) are associated with two types:
 
 1) A "Key" by which information is stored and located
 2) A "Data" which may be anything
 
 For some operations, it may be assumed that comparison operators are defined
 for the key type.
 
 */


#ifndef COMP15_BS_TREE
#define COMP15_BS_TREE 0

#include <cstdlib> 	// NULL, etc.
#include <cassert>	// assert statments
#include <queue>	// FIFO queue for printing
#include <iostream>	// ostream for printing
#include <sstream>	// istringstream for printing

// The easiest way (not always the best way) to write template classes is to
// put everything in the header file.

#include "Map.h"

namespace comp15 { // so that types and functions defined here are put in our special namespace
  
  // A binary search tree Node
  template <typename key_t, typename data_t>
  class BSNode { 
    
  public:
    
    // a data and a key for retrieving it
    key_t key;
    data_t data;
    
    // Binary tree, two subtrees
    BSNode<key_t,data_t> *left;
    BSNode<key_t,data_t> *right;
    
    // constructors for convenience
    BSNode(const key_t &akey, const data_t &adata) : key(akey),data(adata), left(NULL), right(NULL) { }
    
    // find heigh of subtree in O(n) time
    virtual int height() const; 	// defined below
    
    // count all nodes
    unsigned int size () const;
    
    virtual ~BSNode() { } // let someone else do it
    
  };
  
  template <typename key_t, typename data_t>
  int BSNode<key_t,data_t>::height() const { 
    int h = 0; // height of leaf is 0 (going by book's definition)
    if (left) { h = 1+left->height(); } 
    if (right) { 
      int rh = 1+right->height(); // height going right
      h = h > rh ? h : rh; // set h <- max of h, rh
    }
    return h;
  }
  
  template <typename key_t, typename data_t>
  unsigned int BSNode<key_t,data_t>::size() const {
    unsigned int cnt = 1; // me!
    if (left) { cnt += left->size(); }
    if (right) { cnt += right->size(); }
    return cnt;
  }
	
  
  template <typename key_t, typename data_t>
  class BSTree : public Map<key_t,data_t> { 
    
  protected:
    
    BSNode<key_t, data_t> *root; // tree's root
    void clean(BSNode<key_t,data_t>*); // delete subtree
    
  public:
    
    BSTree() { root = NULL; }
    
    // Insert new data in order (return true if new data was added, false if already there)
    virtual bool insert( const key_t &key, const data_t &data );
    
    // Remove node with key, return true iff success (i.e. key was found)
    virtual bool remove( const key_t &key );
    
    // Is the tree empty?
    bool is_empty() const { return root==NULL; }
    
    // compute height in O(n) time
    virtual int height() const { return root ? root->height() : -1; }
    
    // compute size in O(n) time
    unsigned int size() const { return root ? root->size() : 0; }
    
    // Look up item by key
    // Return pointer-to-data or NULL if not found
    virtual data_t* lookup( const key_t &key ); 
    
    // pretty print tree
    void print(std::ostream &out, unsigned int node_width = 1);
    
    // delete all nodes
    virtual ~BSTree() { this->clean(this->root); }
    
  };
  
  template <typename key_t, typename data_t>
  void BSTree<key_t,data_t>::clean(BSNode<key_t,data_t> *node) { 
    if (node) { 
      this->clean(node->left);
      this->clean(node->right);
      delete node;
    }
    
  }
  
  // Look up item by key
  // Return pointer-to-data or NULL if not found
  template <typename key_t, typename data_t>
  data_t* BSTree<key_t,data_t>::lookup( const key_t &key ) { 
    
    BSNode<key_t,data_t> *node = root;
    while ( node ) { 
      
      if (key == node->key) { return &(node->data); }
      else if (key < node->key) { node = node -> left; }
      else { node = node -> right; }
    }
    return NULL; 
    
  }
  
  // Insert new data in order
  template <typename key_t, typename data_t>
  bool BSTree<key_t,data_t>::insert( const key_t &key, const data_t &data ) { 
    
    if (!root) { 
      root = new BSNode<key_t,data_t>(key,data); 
      return true; 
      
    } else {
      // find insert position
      for (BSNode<key_t,data_t> *node = root; node; ) {
        
        if (key < node->key) { 
          if (!node->left) { node->left = new BSNode<key_t,data_t>(key,data); return true; }
          else { node = node->left; }
          
        } else if ( node->key < key ) {
          if (!node->right) { node->right = new BSNode<key_t,data_t>(key,data); return true; }
          else { node = node->right; }
          
        } else { 
          break;
        }
      }
      
      return false;
    }
  }
  
  // Remove node:  replace its position with left subtree and insert right
  // subtree into the rightmost open position in the left subtree
  
  template <typename key_t, typename data_t>
  bool BSTree<key_t,data_t>::remove( const key_t &key ) {
    
    // start with address of root (may need to change what root is pointing to)
    BSNode<key_t,data_t> **parent = &(this->root); 
    
    // search to find address of node with key
    while ( *parent && (*parent)->key != key  ) { 
      if ( key < (*parent)->key ) { parent = &( (*parent)->left ); }
      else                        { parent = &( (*parent)->right ); }
    }
    
    if (*parent) { // found it
      
      BSNode<key_t,data_t> *left_subtree = (*parent)->left;
      BSNode<key_t,data_t> *right_subtree = (*parent)->right;
      
      delete *parent; // delete what *parent is pointing to 
      
      if (left_subtree) { 
        
        *parent = left_subtree; // assign left subtree (arbitrarily) to old position
        
        if (right_subtree) { 
          // insert right subtree in rightmost position in left subtree
          BSNode<key_t,data_t> *t;
          for (t = left_subtree; t->right; t=t->right) { 
          } // (the real purpose of this loop is to find set t)
          t -> right = right_subtree;
        }
        
      } else { 
        // no left subtree at all, just use the right one (which may be NULL)
        
        *parent = right_subtree;
      }
      return true;
      
    } // if key found (*parent != NULL)
    return false; // no match
    
  } // remove
  
  
  template <typename key_t, typename data_t>
  void BSTree<key_t,data_t>::print(std::ostream &out, unsigned int node_width)
  {
    
    if (!root) { out << "(Empty tree)" << std::endl; return; }
    
    const char S = ' ';
    const char B = '.';
    
    const int HEIGHT = this->root->height();
    
    // out << "Tree height = " << HEIGHT;
    
    std::queue<std::pair<BSNode<key_t,data_t>*,int> > Q; // FIFO queue of (node, node height) pairs for visiting tree nodes in breadth-first order
    
    Q.push( std::pair<BSNode<key_t,data_t>*,int>(root, HEIGHT)); // push root only
    
    int current_height = HEIGHT+1; // start one level above (see below)
    
    while (!Q.empty()) { 
      
      // get next node
      std::pair<BSNode<key_t,data_t>*,int> item = Q.front(); Q.pop(); // remove next node
      BSNode<key_t,data_t> *node = item.first; 
      int height = item.second;
      
      // spacer constants for this height
      const unsigned int ISPACE = node_width  * ((1<<height)-1); // space from left to first printed char
      const unsigned int BWIDTH = node_width  * ((1<<height+1)+1); // width of branch
      const unsigned int CSPACE = node_width  * ((1<<height+1)-1); // between nodes
      
      if (height != current_height) { // first node at this level
        
        
        if (height != HEIGHT) { // if height is not height of tree, print spacer level above level 'height'
          
          out << std::endl;
          
          for (unsigned int i=0 ; i < ISPACE ; i++) { out << S; } // print spaces before 
          
          for (int n=0;;)  {  // for all nodes that will be printed at this height
            
            n++; 
            
            for (unsigned int i=0 ; i < BWIDTH;  i++) { out << B; }
            
            if (n == 1 << (HEIGHT-height-1)) { 
              out << std::endl;
              break; // that's all nodes on this level 
            }
            
            for (unsigned int i=0 ; i < CSPACE ; i++) { out << S; }
          }
        }
        
        for (unsigned int i=0 ; i < ISPACE ; i++) { out << S; } // print before-node spacer
        current_height = height;
        
      } else { 
        
        for (unsigned int i=0 ; i < CSPACE;  i++) { out << S; } // print between-node spacer
        
      } 
      
      // print node `node_width' characters wide
      std::ostringstream oss;
      if (node) { oss << node->key; }
      
      for (unsigned int i=0; i<node_width; i++) { oss << S; }
      out << oss.str().substr(0, node_width); 
      
      
      // Add children
      if (height) { 	// enqueue children, including NULL children as placeholders, but not at level zero
        if (node) { 
          Q.push(std::pair<BSNode<key_t,data_t>*,unsigned int>( node->left,  height - 1 ));
          Q.push(std::pair<BSNode<key_t,data_t>*,unsigned int>( node->right, height - 1 ));
        } else { 
          Q.push(std::pair<BSNode<key_t,data_t>*,unsigned int>( NULL, height - 1 ));
          Q.push(std::pair<BSNode<key_t,data_t>*,unsigned int>( NULL, height - 1 ));
        }
      }
      
      
    } // while Q not empty
    
    out << std::endl; // final EOL
    
  } // print
  
} // end namespace 
#endif 