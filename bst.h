#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <vector>
#include <list>

class BST {
	public:
		BST(); // Initialization	
		struct Node {
			int key;
			Node *left;
			Node *right;
		};
		std::string inOrder(Node* root) const;
		Node* insert(Node* node, int key);
		Node* rSearch(Node* node, int key) const;
		Node* iSearchOne(Node* node, int key) const;
		Node* iSearchTwo(int key) const;
		Node* root;

	private:
		Node* newNode(int data);

};

#endif /* BST_H */
