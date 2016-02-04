#include <iostream>
#include <stack>

using namespace std;

struct node
{
	int data;
	node * parent;
	struct node* left;
	struct node* right;
};

node* newNode(int data, int);
void print(node *h);

void printPredSuc(node *root, int v);
bool printPredSucUtil(node *root, node *pred, node *suc, int v);

inline long int max(long int a, long int b){ return (a>b)?a:b; }

node* newNode(int data, node *p = NULL)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->parent = p;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}


void printPredSuc(node *root, int v){
	//successor is the leftmost tree of the right subtree or the first ancestor whose left child gives the subtree of the node
	//predecessor is the rightmost child of the right subtree or the first ancestor such that its right child gives the subtree of the node
	if(!root)
		return;
	node *pred = NULL, *suc = NULL;
	printPredSucUtil(root, pred, suc, v);

}

bool printPredSucUtil(node *root, node *pred, node *suc, int v){
	if(!root)
		return false;

	if(v == root->data){
		//update sucessor in case the right subtree exists
		if(root->right){
			node *r = root->right;
			//the leftmost node in the right subtree
			while(r->left)
				r = r->left;
			suc = r;
		}
		//update predecessor in case the right subtree exists
		if(root->left){
			node *l = root->left;
			while(l->right)
				l = l->right;
			pred = l;
		}
		cout<<"pred = ";
		print(pred);
		cout<<endl;

		cout<<"suc = ";
		print(suc);
		cout<<endl;

		return true;
	}

	if(printPredSucUtil(root->left, pred, root, v))
		return true;

	return printPredSucUtil(root->right, root, suc, v);
}

void morrisInorder(node *root){
	//**check empty tree?

	node *cur = root, *r;

	while(cur){
		if(cur->left){
			//find rightmost node in the left subtree
			r = cur->left;
			while(r->right != NULL && r->right != cur)
				r = r->right;
			if(r->right == NULL){
				//establish a temporary thread and move to the left subtree
				r->right = cur;
				cur = cur->left;
			}
			else if(r->right == cur){
				//we are revisiting a previously made temporary thread. print cur and break this thread and move to the right node
				r->right = NULL;
				cout<<cur->data<<" ";
				cur = cur->right;
			}
		}
		else{
			cout<<cur->data<<" ";
			cur = cur->right;
		}
	}
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
	        10
	      /   \
	    8      21
	  /  \    /
	3     5  11
	  \
	    2


	*/
	node *root = newNode(10, (node *)NULL);
	root->left        = newNode(8,root);
	root->right       = newNode(21,root);
	root->left->left  = newNode(3,root->left);
	root->left->left->right  = newNode(2,root->left->left);  
	root->left->right = newNode(5,root->left);
	root->right->left = newNode(11,root->right);

	cout<<"Morris : "<<endl;
	morrisInorder(root);
	cout<<endl;

	printPredSuc(root, 3);

	return 0;
}
