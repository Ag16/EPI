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
void pritn(node *h);

void printKthInorder(node *root, int k);
bool printKthInorderUtil(node *root, int k, int &curr);

inline long int max(long int a, long int b){ return (a>b)?a:b; }

node* newNode(int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
 
    return newNode;
}

void print(node *h){
	if(!h)
		cout<<"NULL";
	else
		cout<<h->data;
}


void printKthInorder(node *root, int k){
	int curr = 0;
	printKthInorderUtil(root,k,curr);
}

bool printKthInorderUtil(node *root, int k, int &curr){
	if(!root)
		return false;

	if(printKthInorderUtil(root->left, k, curr))
		return true;

	//check if the present node is the one to be printed
	curr++;
	if(curr == k){
		cout<<root->data;
		return true;
	}

	return printKthInorderUtil(root->right,k,curr);

}


/* Driver program to test above functions*/
int main()
{
 
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
 
	printKthInorder(root, 3);
	cout<<endl;

  return 0;
}
