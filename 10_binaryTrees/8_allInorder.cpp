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

void inorder(node *root);
void stackInorder(node *root);
void morrisInorder(node *root);
void parentInorder(node *root);

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

void inorder(node *root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void stackInorder(node *root){
	stack<node *> s;
	node *cur = root;
	int done = 0;

	while(!done){
		//move cur to the leftmost
		while(cur){
			s.push(cur);
			cur = cur->left;
		}
		if(s.empty())
			break;
		//pop cur from the stack
		cur = s.top();
		s.pop();
		cout<<cur->data<<" ";
		cur = cur->right;
	}
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

void parentInorder(node *root){
	node *cur = root, *par;

	cur = root;
	int done = 1;

	while(done){
		//goto the leftmost child
		while(cur->left)
			cur = cur->left;

		//process it
		cout<<cur->data<<" ";

		//if a right child exists then set cur to it and continie
		if(cur->right)
			cur = cur->right;

		//else going up phase begins
		else{
			par = cur->parent;
			while(par && done){
				if(par->left == cur)
					cout<<par->data<<" ";
				
				if(par->left == cur && par->right){
					cur = par->right;
					par = NULL;			//break from this inner loop
				}
				else{
					if(par->parent == NULL)		//to avoid an infinite loop, check whether or not we have reached the root
							done = 0;		//break both inner and outer loops
					else{
						cur = par;
						par = par->parent;
					}
				}			
			}
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
	    8      2
	  /  \    /
	3     5  11
	  \
	    2


	*/
	node *root = newNode(10, (node *)NULL);
	root->left        = newNode(8,root);
	root->right       = newNode(2,root);
	root->left->left  = newNode(3,root->left);
	root->left->left->right  = newNode(2,root->left->left);  
	root->left->right = newNode(5,root->left);
	root->right->left = newNode(11,root->right);

	cout<<"Regular : "<<endl;
	inorder(root);
	cout<<endl;

	cout<<"Stack : "<<endl;
	stackInorder(root);
	cout<<endl;

	cout<<"Morris : "<<endl;
	morrisInorder(root);
	cout<<endl;

	cout<<"Parent Inorder : "<<endl;
	parentInorder(root);
	cout<<endl;

	return 0;
}
