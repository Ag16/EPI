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
vector<vector<int>> findAllSumPaths(node *root, int sum);
void findAllSumPathsUtil(node *root, int sum, vector<int> &ans, int cSum, vector<vector<int>> &ansSet);
inline long int max(long int a, long int b){ return (a>b)?a:b; }

node* newNode(int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
 
    return newNode;
}

vector<vector<int>> findAllSumPaths(node *root, int sum){
	vector<int> ans;
	vector<vector<int>> ansSet;

  int cSum = 0;
	findAllSumPathsUtil(root, sum, ans, cSum, ansSet);
	return ansSet;
}

void findAllSumPathsUtil(node *root, int sum, vector<int> &ans, int cSum, vector<vector<int>> &ansSet){
	if(!root)
		return ;

	cSum += root->data;

	//we could have stopped searching along a path if cSum > sum, but this is only valid if all the numbers are non negative
	//the current question specifies that the tree nodes have integers not non negative intergers associated with them 
	//base case
	if(root->left == NULL && root->right == NULL){
		if(cSum == sum){
      ans.push_back(root->data);
      vector<int> temp(ans);    //create a copy of ans and push it into ansSet
      ansSet.push_back(temp);
      //remove this added node for backtracking
      ans.pop_back();
			return;
		}
		else
			return;
	}

	//backtracking
	ans.push_back(root->data);
	findAllSumPathsUtil(root->left, sum, ans, cSum, ansSet);
	findAllSumPathsUtil(root->right, sum, ans, cSum, ansSet);

	ans.erase(ans.end()-1);
	return;
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
          3     5  11
            \
              2


  */
  node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->left->right  = newNode(2);  
  root->left->right = newNode(5);
  root->right->left = newNode(11);
 
  vector<vector<int>> ansSet = findAllSumPaths(root, sum);
  
  if(ansSet.empty())
  	cout<<"No such path found";
  else{
  	cout<<"The path(s) found :"<<endl;
    for(vector<vector<int>>::iterator ans = ansSet.begin() ; ans != ansSet.end() ; ans++){	
      for(vector<int>::iterator it = (*ans).begin() ; it != (*ans).end() ; it++)
    		cout<<(*it)<<" ";
      cout<<endl;
    }
  }
  cout<<endl;

  return 0;
}
