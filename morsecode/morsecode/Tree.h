
#pragma once
using namespace std;

class Node {
	friend class tree;
private:
	Node *lchild, *rchild;
	char data;
public:
	Node(char x) {
		data = x;
		lchild = rchild = NULL;
	}
};
class tree {
public:
	tree() { root = NULL; }
	Node* root;
	int insert(char item, string instructions,Node* curr);
	void tree::print(string text);

};
// this function builds the tree
int tree::insert(char item, string instructions, Node *currNode) {
	if (root == NULL) {

		root = new Node(' ');
		currNode = root;
		
	}
	// if the children are empty we make a placeholder variable to insert the char later for
	// both left and right children
	if (currNode->lchild == NULL) {
		currNode->lchild = new Node(' ');
	}
	if (currNode->rchild == NULL) {
		currNode->rchild = new Node(' ');
	}

	//if the morse instructions is a dot we want to traverse the tree left and call the function recursivly 
	if (instructions[0] == '.') {
		currNode = currNode->lchild;
		insert(item, instructions.substr(1), currNode);
	}
	//if the instructions is a dash we want to traverse the tree right and call the function recursivly 
	else if (instructions[0] == '_') {
		currNode = currNode->rchild;
		insert(item, instructions.substr(1), currNode);
		}
	//once we finished the instructions we want to give that node the character value assosiated with it
	if (instructions[0] == ' ' || instructions.size() == 0) {
		currNode->data = item;
		return 0;
	}
}


// print function to get morse to text geting one code at a time
void tree::print(string text) {
	Node *currNode = root;
	Node *temp = currNode;

	for (int i = 0; i < text.length(); i++) {


		if (text[i] == '.') {
			currNode = currNode->lchild;
		}

		else if (text[i] == '_') {
			currNode = currNode->rchild;
		}

		
	
	}
	cout << currNode->data;
	currNode = root;
};
