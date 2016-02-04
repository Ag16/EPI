#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

struct node
{
	char data;
	node * parent;
	struct node* left;
	struct node* right;
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

	return newNode;
}


void print(node *h){
	if(!h)
		cout<<"NULL";
	else
		cout<<h->data;
}

void preorder(node *root){
	if(!root)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node *root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

node *reconstructPostUtil(string t, int &i){
	if(i < 0)
		return NULL;
	char c = t[i];
	i--;
	if(c == '$')
		return NULL;

	node *temp = newNode(c);
	temp->right = reconstructPostUtil(t,i);
	temp->left = reconstructPostUtil(t, i);
	return temp;
}

node *reconstructPost(string t){
	int i = t.size()-1;
	return reconstructPostUtil(t, i);
}

node * reconstructPre(string t){
	//null denoted by $
	stack<node *>s;
	node *cur;
	char c;
	node *temp;

	//intitalise the stack and root of tree
	temp = newNode(*(t.begin()));
	node *root = temp;
	s.push(temp);

	for(string::iterator it = t.begin()+1 ; it != t.end();){
		c = *it;
		if(c != '$'){
			temp = newNode(c);
			cur = s.top();		//the stack will never be empty while a new node is being formed as the node has to be the child of something
			if(cur->left){					//and the parent will always be in the stack as long as the input is correct
				cur->right = temp;
				s.pop();
			}
			else
				cur->left = temp;

			s.push(temp);
			it++;
		}
		else{
			//check the next character in the string as well
			it++;
			c = *it;
			if(c == '$'){
				//pop the top as the node on top is a leaf node
				s.pop();

				//keep popping from the stack for each null after this as all these nodes have NULL right children
				it++;
				while(it != t.end() && *it == '$'){
					s.pop();
					it++;
				}
			}
			else{
				cur = s.top();
				temp = newNode(c);
				cur->right = temp;
				s.pop();
				s.push(temp);
				it++;
			}
		}
	}
	return root;
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
	node *root = newNode('A', (node *)NULL);
	root->left        = newNode('B',root);
	root->right       = newNode('C',root);
	root->left->left  = newNode('D',root->left);
	root->left->left->right  = newNode('G',root->left->left);  
	root->left->right = newNode('E',root->left);
	root->right->left = newNode('F',root->right);

	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;

	string s = "ABD$G$$E$$CF$$$";
	node *root2 = reconstructPre(s);

	preorder(root2);
	cout<<endl;
	inorder(root2);
	cout<<endl;

	string s2 = "$$$GD$$EB$$F$CA";
	node *root3 = reconstructPost(s2);

	preorder(root3);
	cout<<endl;
	inorder(root3);
	cout<<endl;
	return 0;
}
