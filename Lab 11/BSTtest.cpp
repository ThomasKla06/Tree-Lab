#include<iostream>
#include "BST.h"
using namespace std;

//Thomas Klaesges

int main() {
	BST tree;

	tree.insert(30);
	if (tree.lookup(30)) {
		cout << "Found 30" << endl;
	}
	if (!tree.lookup(10)) {
		cout << "Not found 10" << endl;
	}
	tree.insert(30); //Should not insert it 
	tree.insert(15);
	tree.insert(20);
	tree.insert(45);
	tree.insert(10);
	tree.insert(50);
	tree.insert(18);
	tree.insert(25);
	tree.insert(55);

	cout << "Printing list:" << endl;
	tree.print();

	if (tree.lookup(10)) {
		cout << "Found 10" << endl;
	}
	else {
		cout << "error 10 not found" << endl;
	}
	if (tree.lookup(50)) {
		cout << "Found 50" << endl;
	}
	else {
		cout << "error 50 not found" << endl;
	}
	if (!tree.lookup(100)) {
		cout << "100 not found" << endl;
	}
	else {
		cout << "error 100 found" << endl;
	}

	cout << endl; 

	cout << "removing 18:" << endl;
	tree.remove(18);

	tree.print();

	tree.insert(18);

	cout << "Reinserted 18" << endl;
	cout << "removing 45 " << endl;
	tree.remove(45);

	tree.print();

	cout << "Removing 15:" << endl;
	tree.remove(15);

	tree.print();
}