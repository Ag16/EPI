//cfunction to check whether or not a binary tree is balanced or not

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
bool checkBalance(node *root);
bool checkBalanceUtil(node *root, long int &h);
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

bool checkBalance(node *root){
	long int height;
	return checkBalanceUtil(root, height);
}


bool checkBalanceUtil(node *root, long int &h){
	if(root == NULL){			//base case
		h = 0;
		return true;
	}

	long int h1,h2;
	bool a1,a2;

	a1 = checkBalanceUtil(root->left, h1);
	if(!a1)
		return false;

	a2 = checkBalanceUtil(root->right, h2);
	if(!a2)
		return false;

	h = max(h1, h2)+1;

	int diff = h1 - h2;

	if(diff == 0 || diff == 1 || diff == -1)
		return true;

	//we get to this point if the subtree is unbalanced
	return false;

}

 
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(6);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
 	root->left->left->left->left = newNode(10);
    if(checkBalance(root))
    	cout<<"Tree is balanced"<<endl;
    else
    	cout<<"Tree is not balanced"<<endl;    
 
     return 0;
}