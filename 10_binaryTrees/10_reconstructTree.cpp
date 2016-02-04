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

node *reconstructTree(int *pre, int *in);
node *reconstructTreeUtil(int *pre, int *in, int ps, int pe, int is, int ie, int n);

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

node *reconstructTree(int *pre, int *in, int n){
	int ps=0, pe=n-1, is=0, ie=n-1;
	node *root = reconstructTreeUtil(pre, in, ps, pe, is, ie, n);
	return root;
}

node *reconstructTreeUtil(int *pre, int *in, int ps, int pe, int is, int ie, int n){
	if(ps > pe || is>ie || pe >=n || ie >=n || is<0 || pe<0)
		return NULL;

	int d = pre[ps];
	int i;
	for(i=is ; i <= ie && in[i] != d; i++);

	//make the newnode
	node *root = newNode(d);
	
	root->left = reconstructTreeUtil(pre, in, ps+1, ps+i-is, is, i-1, n);
	root->right = reconstructTreeUtil(pre, in, ps+i-is+1, pe, i+1, ie, n);
	return root;
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

void preorder(node *root){
	if(!root)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
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

	cout<<"In : "<<endl;
	morrisInorder(root);
	cout<<endl;
	cout<<"Pre : "<<endl;
	preorder(root);
	cout<<endl;


	int in[] = {3,2,8,5,10,11,21};
	int pre[] = {10,8,3,2,5,21,11};
	node *root2 = reconstructTree(pre, in, 7);
	
	cout<<"In : "<<endl;
	morrisInorder(root2);
	cout<<endl;
	cout<<"Pre : "<<endl;
	preorder(root2);
	cout<<endl;
	return 0;
}
