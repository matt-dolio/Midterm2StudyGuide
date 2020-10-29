#include <iostream>
#include <vector>
#include "bst.h"

using namespace std;

void checkInOrder();
void testRecursiveEmpty();
void testRecursiveSearch();
void testIterativeEmpty();
void testIterativeSearchOne();
void testIterativeSearchTwo();

int main () {
	checkInOrder();
	testRecursiveEmpty();
	testRecursiveSearch();
	testIterativeEmpty();
	testIterativeSearchOne();
	testIterativeSearchTwo();
	return 0;
}

void checkInOrder() {
	BST *test = new BST();
	test->root = test->insert(test->root, 14);
	test->root = test->insert(test->root, 17);
	test->root = test->insert(test->root, 6);
	test->root = test->insert(test->root, 3);
	test->root = test->insert(test->root, 10);
	test->root = test->insert(test->root, 15);
	test->root = test->insert(test->root, 19);
	cout << "Test InOrder function (next line):" << endl;
	cout << test->inOrder(test->root) << endl;
	cout << "Should be the list above me ^^" << endl;
	delete test;
}

void testRecursiveEmpty() {
	BST *empty = new BST();
	if (empty->rSearch(empty->root, 0) == nullptr) cout << "Empty recursion Passed!" << endl;
	else cout << "Empty recursion Failed!" << endl;
	delete empty;
}

void testRecursiveSearch() {
	BST *b = new BST();
	b->root = b->insert(b->root, 6);
	b->root = b->insert(b->root, 2);
	b->root = b->insert(b->root, 3);
	b->root = b->insert(b->root, 4);
	if (b->rSearch(b->root, 4)->key == 4) cout << "Search recursion Success! Found 4" << endl;
	else cout << "Search recursion Failed to find 4" << endl;
	if (b->rSearch(b->root, 5) == nullptr) cout << "Search recursion Didn't find 5" << endl;
	else cout << "Search recursion Found 5 somehow" << endl;
	delete b;
}

void testIterativeEmpty() {
	BST *empty = new BST();
	if (empty->iSearchOne(empty->root, 42) == nullptr) cout << "Empty iteration Passed!" << endl;
	else cout << "Empty iteration Failed!" << endl;
	delete empty;
}

void testIterativeSearchOne() {
	BST *b = new BST();
	b->root = b->insert(b->root, 5);
	b->root = b->insert(b->root, 12);
	b->root = b->insert(b->root, 18);
	b->root = b->insert(b->root, 6);
	b->root = b->insert(b->root, 7);
	b->root = b->insert(b->root, 4);
	if (b->iSearchOne(b->root, 4)->key == 4) cout << "Search iteration Passed!" << endl;
	else cout << "Search iteration Failed!" << endl;
	delete b;
}

void testIterativeSearchTwo() {
	BST *b = new BST();	
	b->root = b->insert(b->root, 4);
	b->root = b->insert(b->root, 3);
	b->root = b->insert(b->root, 5);
	b->root = b->insert(b->root, 8);
	b->root = b->insert(b->root, 6);
	if (b->iSearchTwo(6)->key == 6) cout << "Queue iteration Passed!" << endl;
	else cout << "Queue iteration Failed!" << endl;
	delete b;
}
