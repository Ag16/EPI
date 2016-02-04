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

void addNextNodesQueue(node *root){
	//add right siblings while taking O(n) space
	queue<node *>q;
	int count;
	node *it;
	q.push(root);

	while(!q.empty()){
		count = q.size();
		while(count-- > 0){
			it = q.front();
			q.pop();
			if(count != 0){		//if we are not at the last node of the current level
				it->next = q.front();
			}
			else
				it->next = NULL;
			if(it->left)
				q.push(it->left);
			if(it->right)
				q.push(it->right);
		}
	}
}

node *getNext(node *par){
	//hlper functino for addnNextNodes

	//return the leftmost child starting from par and all its right siblings
	if(!par)
		return NULL;

	//goto first sibling with a child
	while(par && !par->left && !par->right)
		par = par->next;
		
		node *n;

		if(!par)	//if we reached the end of the level then break out fo the loop
			return NULL;

		if(par->left)	//assign the leftmost child of par as n
			n = par->left;
		else
			n = par->right;
		return n;
}

void addNextNodes(node *root){
	//takes no extra space
	node *par, *n;
	if(root->left){
		n = root->left;
		n->next = root->right; 
	}
	else
		n = root->right;

	while(n){
		//n points to the next parent node of the next level that has to be processed
		par = n;
		//now we find the next n and the first child of the nodes on this level
		n = getNext(par);
		if(!n)
			break;
		//now the joining starts, the nodes at the level of par are already joined
		while(par){
			if(par->left){
				if(par->right){
					par->left->next = par->right;
					par->right->next = getNext(par->next);
				}
				else
					par->left->next = getNext(par->next);
			}
			else if(par->right){
				par->right->next = getNext(par->next);
			}
			par = par->next;
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

	node *it;

	addNextNodes(root);

	it=root;
	while(it){
		cout<<it->data<<" ";
		it = it->next;
	}
	cout<<endl;

	it=root->left;
	while(it){
		cout<<it->data<<" ";
		it = it->next;
	}
	cout<<endl;

	it=root->left->left;
	while(it){
		cout<<it->data<<" ";
		it = it->next;
	}
	cout<<endl;

	it=root->left->left->right;
	while(it){
		cout<<it->data<<" ";
		it = it->next;
	}
	cout<<endl;

}
