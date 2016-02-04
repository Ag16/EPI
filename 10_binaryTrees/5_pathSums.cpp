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

void findSumUtil(node *root, unsigned long &sum, unsigned int n){
	if(!root)
		return;

	n = n << 1;
	n = n | root->data;

	if(root->left == NULL && root->right == NULL){			//if n is a leaf node
		sum += n;
		return;
	}
	else{
		findSumUtil(root->left, sum, n);
		findSumUtil(root->right, sum, n);
	}
}

unsigned long findSum(node *root){
	if(!root)
		return 0;
	unsigned long sum = 0;
	unsigned int n=0;
	findSumUtil(root, sum, n);
	return sum;
}


void print(node *h){
	if(!h)
		cout<<"NULL";
	else
		cout<<h->data;
}

int main()
{
    
	node * root = newNode(1);
    root->left = newNode(0);
    root->right = newNode(1);
    
    root->left->left = newNode(0);
    root->left->left->left = newNode(0);
    root->left->left->right = newNode(1);

    root->left->right = newNode(1);
    root->left->right->right = newNode(1);
    root->left->right->right->left = newNode(0);

    root->right->left = newNode(0);
    root->right->left->right = newNode(0);
    root->right->left->right->left = newNode(1);
    root->right->left->right->right = newNode(0);
    root->right->left->right->left->right = newNode(1);
    

    root->right->right = newNode(0);
    root->right->right->right = newNode(0);

    unsigned long sum = findSum(root);
    cout<<"Sum is = "<<sum<<endl;
	return 0;
}
