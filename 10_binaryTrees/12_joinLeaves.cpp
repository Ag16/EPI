#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct node
{
	char data;
	node * parent;
	struct node* left;
	struct node* right;
	node *next;
};

node* newNode(char data, node *);
void print(node *h);

node* newNode(char data, node *n = NULL)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->parent = n;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->next = NULL;
	return newNode;
}

void inorderPrint(node *root){
	//the nodes of the leaves are being used in the linked list
	//as a result of this the tree is no longer a binary tree
	//we can se other approaches like making a linked list of node pointers and adding these nodes to it
	//in that case too the logic will remain the same
	if(!root)
		return;
	inorderPrint(root->left);
	cout<<root->data<<" ";
	inorderPrint(root->right);
}

void joinLeafeNodesUtil(node *root, node **cur){
	if(!root)
		return;
	if(root->left == NULL && root->right == NULL){
		(*cur)->right = root;
		root->left = *cur;
		*cur = root;
	}
	else{
		joinLeafeNodesUtil(root->left, cur);
		joinLeafeNodesUtil(root->right, cur);
	}

}

node *joinLeafeNodes(node *root){
	node *head = newNode(0);
	node *cur = head;

	joinLeafeNodesUtil(root, &cur);
	cur = head->right;
	delete head;
	return cur;
}


void print(node *h){
	if(!h)
		cout<<"NULL";
	else
		cout<<h->data;
}
/* Driver program to test above functions*/
int main()
{

	/* Constructed binary tree is
	        A
	      /   \m
	    B      C
	  /  \    /
	D     E  F
	  \
	    G


	*/
	node *root = newNode('A', (node *)NULL);
	root->left        = newNode('B',root);
	root->right       = newNode('C',root);
	root->left->left  = newNode('D',root->left);
	root->left->right = newNode('E',root->left);
	root->right->left = newNode('F',root->right);
	root->left->left->right  = newNode('G',root->left->left);  

	inorderPrint(root);
	cout<<endl<<"---------"<<endl;

	node *head = joinLeafeNodes(root);

	for(node *it = head ; it != NULL ; it = it->right)
		cout<<it->data<<"  ";
	cout<<endl;

}
