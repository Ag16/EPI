//program to print alternating level order traversal of a  binary tree
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a new Binary Tree Node
struct Node *newNode(char item)
{
    struct Node *temp =  new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
 // A utility function to print indorder traversal of a
// binary tree
void printInorder(struct Node *root)
{
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}



void printAlternatingLevels(Node *root){
	Node *it = root;
	stack<Node *> se, so;
	int level = 0, n;
	se.push(it);
	double sum;

	while(!se.empty() || !so.empty()){
		sum = 0;		//for the average

		if(!se.empty() ){		//even level case
			n = se.size();
			while(!se.empty()){
				it = se.top();
				se.pop();
				
				cout<<it->data<<" ";
				sum += it->data;
				
				if(it->left)
					so.push(it->left);
				if(it->right)
					so.push(it->right);
			}
		}
		else if(!so.empty() ){		//odd level case
			n = so.size();
			while(!so.empty()){
				it = so.top();
				so.pop();

				cout<<it->data<<" ";
				sum += it->data;

				if(it->right)
					se.push(it->right);
				if(it->left)
					se.push(it->left);
			}
		}

		//print the average;
		cout<<"\t\t\taverage = "<<sum/n;
		cout<<endl;			//print newline at the end of the current level
		level++;
	}
}

int main(){
	struct Node *root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    root->right->right = newNode('g');
    root->left->left->left = newNode('h');
    root->left->left->right = newNode('i');
    root->left->right->left = newNode('j');
    root->left->right->right = newNode('k');
    root->right->left->left = newNode('l');
    root->right->left->right = newNode('m');
    root->right->right->left = newNode('n');
    root->right->right->right = newNode('o');
 
    cout << "Inorder Traversal of given tree\n";
    printInorder(root);

    cout<<endl<<"Spiralling level order traversal is\n";
    printAlternatingLevels(root);

	return 0;
}