#include "bst.h"

#include <list>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

BST::BST() {
	// constructor sets the root to null
	root = nullptr;
}

BST::Node* BST::newNode(int data) {
	Node* temp = new Node();
	temp->key = data;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

BST::Node* BST::insert(Node* node, int key) {
	if (node == nullptr) {
		return newNode(key);
	}

	if (node->key > key) node->left = insert(node->left, key);
	else if (node->key < key) node->right = insert(node->right, key);

	// return the unchanged node pointer
	return node;
}

std::string BST::inOrder(Node* root) const {
	if (root == nullptr) return "";
	else return inOrder(root->left) + to_string(root->key) + '\n' + inOrder(root->right);
}

// Recursive search
BST::Node* BST::rSearch(Node* root, int key) const {
	// Base case
	if (root == nullptr) return nullptr;
	
	if (key < root->key) {
		return rSearch(root->left, key);
	} else if (key > root->key) {
		return rSearch(root->right, key);
	} else {
		// best case! you found it!
		return root;
	}

}

// Iterative if the function is passed the Node* in the argument
// Credit: Lawton Nichols (our professor, duh)
BST::Node* BST::iSearchOne(Node* root, int key) const {
	// search from the root for a key
	// keep searching as long as we haven't hit the bottom of the tree
	while (root != nullptr) {
		if (key < root->key) {
			// go left
			root = root->left;
		} else if (key > root->key) {
			// go right
			root = root->right;
		} else {
			// yay! you found it!
			return root;
		}
	}

	// if we get here, couldn't find the key
	return nullptr;
}

/* Short bit on the <queue> library:

   From the cplusplus reference:
   Queues are a type of container *adapter* that 
   operates in a FIFO (that is, first-in first-out) context. 

   If no container type (deque, list, etc) is defined, the 
   queue will use a standard "deque" container.

   member functions include:
   empty();  				// RETURNS BOOLEAN
   size();   				// RETURNS UNSIGNED INTEGRAL
   back();   				// RETURNS REFERENCE TO LAST ELEMENT
   front();  				// RETURNS REFERENCE TO FRONT ELEMENT
   push(type<T> val); 		// NO RETURN, INSERTS NEW ELEMENT AT END OF QUEUE
   emplace(args); 			// NO RETURN, INSERTS NEW ELEMENT AT END OF QUEUE (WITH ARGS)
   pop();					// NO RETURN, REMOVES ELEMENT AT FRONT OF QUEUE
   swap(queue& q);			// NO RETURN, SWAPS VALUES BETWEEN QUEUES OF SAME TYPE

*/

// Iterative search using <queue> library
BST::Node* BST::iSearchTwo(int key) const {
	// dually checks if the root is null or if we have the key in the initial root.
	if (root == nullptr or root->key == key) return root;

	queue<Node *> q;

	// we want to NQ (enqueue) the root
	q.push(root);

	while (q.empty() == false) {
		Node* node = q.front();
		// if this is true, we're done! we found it :D
		if (node->key == key) return node;
		
		// remove the current node and enqueue its children
		q.pop();
		if (node->left != nullptr) q.push(node->left);
		if (node->right != nullptr) q.push(node->right);
	}

	// otherwise, it didn't find anything
	return nullptr; // :^(
}

















