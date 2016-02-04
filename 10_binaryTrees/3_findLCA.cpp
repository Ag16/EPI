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


int findLCAUtil(node *root, int d1, int d2, node **LCA){
	//we assume that all nodes have unique values
	if(*LCA)
		return 2;
	if(root == NULL)
		return 0;

	int found=0;
	found += ((root->data == d1)||(root->data == d2));
	found += findLCAUtil(root->left, d1, d2, LCA);
	if(*LCA)
		return 2;
	else if(found == 2){
		if(*LCA == NULL)
			*LCA = root;
		return 2;
	}

	found += findLCAUtil(root->right, d1, d2, LCA);
	if(*LCA)
		return 2;
	else if(found == 2){
		if(*LCA == NULL)
			*LCA = root;
		return 2;
	}

	return found;
}

node *findLCA(node *root, int d1, int d2){
	node *lca = NULL;
	findLCAUtil(root, d1, d2, &lca);
	return lca;
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
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout<<"LCA(4, 5) = ";
    print(findLCA(root, 4, 5));
    cout<<endl<<"\nLCA(4, 6) = ";
    print(findLCA(root, 4, 6));
    cout<<endl<<"\nLCA(3, 4) = ";
    print(findLCA(root, 3, 4));
    cout<<endl<<"\nLCA(2, 4) = ";
    print(findLCA(root, 2, 4));
    cout<<endl<<"\nLCA(2, 3) = ";
    print(findLCA(root, 2, 3));
    cout<<endl;

	return 0;
}
