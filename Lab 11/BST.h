#pragma once
#include <iostream>
using namespace std;
/*
* Authors:
* 2024.11.12 Alexi
* [your name goes here]
*/

//Simple Binary Tree Node class
class BNode {
public:
	const int data;
	BNode* left{ nullptr };
	BNode* right{ nullptr };
	//Constructor takes data only
	//Set the left and right children manually
	BNode(int d) : data(d) {}
};

class BST {
private://Fields
	int size{ 0 };
	BNode* root{ nullptr };
public:
	//Constructor
	BST() {
		//Intentionally empty
	}

	//Private Helper Methods
private:
	//TODO (either insertHelper or lookupHelper,
	//  plus any other helper methods you want)

	BNode* insertHelper(BNode* node, int val) {
		if (node == nullptr) {
			BNode* newNode = new BNode{ val };
			return newNode;
		}
		else if (node->data < val) {
			node->right = insertHelper(node->right, val);
		}
		else {
			node->left = insertHelper(node->left, val);
		}
		return node;
	}
	//Finds the minimum value of a subtree, for use in case three removals
	int findMin(BNode* node) {
		BNode* current{ node };
		while (current->left != nullptr) {
			current = current->left;
		}
		return current->data;
	}
	//Methods
public:
	//Inserts a new node in the tree recursively
	void insert(int val) {
		if (lookup(val)) {
			return;
		}
		root = insertHelper(root, val);
		size++;
	}
//Finds a val in the tree iteratively
	bool lookup(int val) {
		bool foundTarget{ false };
		BNode* current{ root };
		if (current == nullptr) {
			return false;
		}
		else {
			BNode* current{ root };
			while (!foundTarget && current != nullptr) {
				if (current->data < val) {
					current = current->right;
				}
				else if (current->data > val) {
					current = current->left;
				}
				else {
					foundTarget = true;
				}
			}
			return foundTarget;
		}
	}

	void inOrder(BNode* current) {
		if (current != nullptr) {
			inOrder(current->left);
			cout << current->data << " ";
			inOrder(current->right);
		}
	}

	void print() {
		inOrder(root);
		cout << endl;
	}

	void remove(int val) {
		BNode* current{ root };
		BNode* parent{ root };
		bool foundTarget{ false };
		if (root == nullptr) {
			return;
		}
		else {
			while (!foundTarget && current != nullptr) {
				if (current->data < val) {
					parent = current;
					current = current->right;
				}
				else if (current->data > val) {
					parent = current;
					current = current->left;
				}
				else {
					foundTarget = true;
				}
			}
			if (current->left == nullptr && current->right == nullptr) {
				//Deleting node with no children
				if (current->data > parent->data) {
					parent->right = nullptr;
					delete current;
				}
				else {
					parent->left = nullptr;
					delete current;
				}
			}
			else if (current->left == nullptr && current->right != nullptr) {
				//Deleting node with one child
				if (current->data < parent->data) {
					parent->left = current->right;
				}
				else {
					parent->right = current->right;
				}
				delete current;
			}
			else if (current->right == nullptr && current->left != nullptr) {
				//Also deleting node with one child
				if (current->data < parent->data) {
					parent->left = current->left;
				}
				else {
					parent->right = current->left;
				}
				delete current;
			}
			else if (current->right != nullptr && current->left != nullptr) {
				//Delete a node with 2 children
				BNode* newNode{ current->right };
				BNode* minNode = new BNode{ findMin(newNode) };
				remove(minNode->data);
				if (current->data < parent->data) {
					parent->left = minNode;
				}
				else {
					parent->right = minNode;
				}
				minNode->left = current->left;
				minNode->right = current->right;
				delete current;
			}
		}
	}
};