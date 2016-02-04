//make a linked list api
#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct node{
	int d;
	node *left;
	node *right;
};

node *newNode(int v){
	node *t = new node;
	t->d = v;
	t->left = t->right = NULL;
	return t;
}

void nonRecInorder(node *root){
	node *it;
	stack<node *> s1;

	it = root;
	do{
		//goto the leftmost child of it while pushing each node into the stack
		while(it){
			s1.push(it);
			it = it->left;
		}

		//pop into it the top of the stack, process it and move to the right child
		it = s1.top();
		s1.pop();
		cout<<it->d<<" ";
		it = it->right;
	}while(!s1.empty());
}

int main(){
	//create the tree
	node *it = newNode(34);
	it->left = newNode(20);
	it->right = newNode(40);
	it->left->left = newNode(5);
	it->left->right = newNode(25);
	it->left->right->left = newNode(23);
	it->left->left->right = newNode(6);
	it->right->left = newNode(36);
	it->right->right = newNode(100);

	nonRecInorder(it);
	cout<<endl;
	return 0;
}