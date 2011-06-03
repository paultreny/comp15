// Paul Reny - 11/06/02 - COMP 15
// LAB 1
// FILE: Node.h
// CLASS PROVIDED: Node (part of the namespace
// reny_paul_namespc_one)

#ifndef RENY_PAUL_NAMESPC_ONE
#define RENY_PAUL_NAMESPC_ONE

#include <cstdlib> // provides NULL
#include <string> // provides use of strings

namespace reny_paul_namespc_one
{
	class Node
	{
	public:
		// Precondition: value_type is any of the C++
		// built-in types, or a class with both a 
		// default & copy constructor
		typedef std::string value_type;
		// Postcondition: value_type is a variable of
		// the type specified in the Precondition
		Node(const value_type& init_node_data = value_type(), Node* init_next_node = NULL) { node_data=init_node_data; next_node=init_next_node; }
		// Postcondition: the Node contains default or supplied
		// initial data and pointer to the next node		
		Node* get_next() { return next_node;}
		// Postcondition: The pointer from this node to the 
		// next is returned
		void set_data(const value_type& new_data) { node_data = new_data; }
		// Postcondition: (const) The Node contains the 
		// specified new_data		 
		void set_next(Node* new_node) { next_node=new_node; }		
		// Postcondition: The Node contains the specified 
		// new_node pointer
		value_type get_data() const { return node_data; }
		// Postcondition: (const)The data from this node is 
		// returned
		const Node* get_next() const { return next_node; }
		// Postcondition: (const) The pointer from this node to
		// the next is returned
	private:
		value_type node_data; // the node's data
		Node *next_node; // pointer to the next node
	};
};
#endif
