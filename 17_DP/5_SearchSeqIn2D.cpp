#include <iostream>
#include <string>
#include <unordered_set> 
#include <tuple>
#include <functional>
#include <vector>

using namespace std;

struct tupleHash{
	size_t operator()(const tuple<int,int,int> &a)const{
		hash<int> intHash;
		return intHash(get<0>(a)) ^ intHash(get<1>(a)) ^ intHash(get<2>(a));
	}
};

bool findArrayIn2DUtil(const vector<vector<int>> &A, const vector<int> &S, int i, int j, int k, unordered_set<tuple<int,int,int>, tupleHash> &visited){
	//check for out of bound mememory references
	if(i<0 || j<0 || i>A.size() || j>A[i].size())
		return false;

	//check if the i,j pair has already been visited for S[k] before
	if(visited.find(make_tuple(i,j,k)) != visited.end())
		return false;

	//check for equality
	if(A[i][j] == S[k]){
		if(k == S.size()-1)
			return true;

		int x[] = {-1,1};
		for(auto y:x){
			if(findArrayIn2DUtil(A,S,i+y,j,k+1,visited))
				return true;
			visited.insert(make_tuple(i+y,j,k));
		}
		for(auto y:x){
			if(findArrayIn2DUtil(A,S,i,j+y,k+1,visited))
				return true;
			visited.insert(make_tuple(i,j+y,k));
		}
	}
	return false;
}

bool findArrayIn2D(const vector<vector<int>> &A, const vector<int> &S){
	unordered_set<tuple<int, int, int>, tupleHash> visited;
	for(int i=0 ; i<A.size() ; i++){
		for(int j=0 ; j<A[i].size() ; j++){
			if(findArrayIn2DUtil(A, S,i,j,0,visited))
				return true;
		}
	}
	return false;
}

int main(){
	vector<int> S({1,3,4,6});
	vector<vector<int>> A;
	A.push_back(vector<int>({1,2,3}));
	A.push_back(vector<int>({3,4,5}));
	A.push_back(vector<int>({5,6,7}));

	if(findArrayIn2D(A,S))
		cout<<"Array found in the matrix!!"<<endl;
	else
		cout<<"Array NOT found in the matrix!!"<<endl;

	return 0;
}