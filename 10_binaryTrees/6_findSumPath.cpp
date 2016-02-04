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
vector<int> findSumPath(node *root, int sum);
bool findSumPathUtil(node *root, int sum, vector<int> &ans, int cSum);

inline long int max(long int a, long int b){ return (a>b)?a:b; }

node* newNode(int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
 
    return newNode;
}

vector<int> findSumPath(node *root, int sum){
	vector<int> ans;
	int cSum = 0;
	findSumPathUtil(root, sum, ans, cSum);
	return ans;
}

bool findSumPathUtil(node *root, int sum, vector<int> &ans, int cSum){
	if(!root)
		return false;

	cSum += root->data;

	//we could have stopped searching along a path if cSum > sum, but this is only valid if all the numbers are non negative
	//the current question specifies that the tree nodes have integers not non negative intergers associated with them 
	//base case
	if(root->left == NULL && root->right == NULL){
		if(cSum == sum){
			ans.push_back(root->data);
			return true;
		}
		else
			return false;
	}

	//backtracking
	ans.push_back(root->data);
	if(findSumPathUtil(root->left, sum, ans, cSum))
		return true;
	if(findSumPathUtil(root->right, sum, ans, cSum))
		return true;

	ans.erase(ans.end()-1);
	return false;
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
 
  int sum = 23;
 
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
 
  vector<int>ans = findSumPath(root, sum);
  
  if(ans.empty())
  	cout<<"No such path found";
  else{
  	cout<<"The path found is :"<<endl;
  	for(vector<int>::iterator it = ans.begin() ; it != ans.end() ; it++)
  		cout<<(*it)<<" ";
  }
  cout<<endl;

  return 0;
}
