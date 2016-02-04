#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

node* newNode(int data);
node* newNode(int data);

inline long int max(long int a, long int b){ return (a>b)?a:b; }

node* newNode(int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
 
    return newNode;
}

bool checkSym(node *root){
	if(!root)
		return true;
	return checkSymUtil(root->left, root->right);
}

void print(node *n){
	if(!n)
		cout<<"NULL"<<" ";
	else
		cout<<n->data<<" ";
}

bool checkSymUtil(node *n1, node *n2){
	if(n1 == NULL && n2 == NULL)
		return true;

	if(n1 && n2)
		return (n1->data == n2->data) && checkSymUtil(n1->left, n2->right) && checkSymUtil(n1->right, n2->left);
	else
		return false;
}

int main()
{
    
	node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(4);
    root->right->left  = newNode(4);
    root->right->right = newNode(3);

   	if(checkSym(root))
    	cout<<"Tree is symmetric"<<endl;
    else
    	cout<<"Tree is not symmetric"<<endl;    
 
     return 0;
}
