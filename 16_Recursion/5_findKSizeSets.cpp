#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int,int> xy;

template<typename T> 
void findKSetUtil(const vector<T> &a, vector<T> &p, int c, vector<vector<T>> &ans, int k){
	if(k==0){
		ans.push_back(p);
		return;
	}
	if(c == a.size())
		return;

	p.push_back(a[c]);
	findKSetUtil(a,p,c+1,ans,k-1);
	p.pop_back();
	findKSetUtil(a,p,c+1,ans,k);
}

//find all subsets
template<typename T>
vector<vector<T>> findKset(const vector<T> &a, int k){
	vector<vector<T>> ans;
	vector<T> p;
	findKSetUtil(a,p,0,ans,k);
	return ans;
}

template <typename T>
void printVector(const vector<T> &a){
	for(typename::vector<T>::const_iterator it = a.cbegin() ; it != a.cend() ; it++)
		cout<<*it<<" ";
}

int main(){
	vector<int> a({1,2,3,4,5});
	vector<vector<int>> ans = findKset(a,2);

	for(vector<vector<int>>::iterator it = ans.begin() ; it != ans.end() ; it++){
		cout<<"{ ";
		printVector(*it);
		cout<<"}"<<endl;
	}
}
