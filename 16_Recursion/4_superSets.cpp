#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int,int> xy;

template<typename T> 
void findSupersetUtil(const vector<T> &a, vector<T> &p, int c, vector<vector<T>> &ans){
	if(c == a.size()){
		ans.push_back(p);
		return;
	}
	p.push_back(a[c]);
	findSupersetUtil(a,p,c+1,ans);
	p.pop_back();
	findSupersetUtil(a,p,c+1,ans);
}

//find all subsets
template<typename T>
vector<vector<T>> findSuperset(const vector<T> &a){
	vector<vector<T>> ans;
	vector<T> p;
	findSupersetUtil(a,p,0,ans);
	return ans;
}

template <typename T>
void printVector(const vector<T> &a){
	for(typename::vector<T>::const_iterator it = a.cbegin() ; it != a.cend() ; it++)
		cout<<*it<<" ";
}

int main(){
	vector<int> a({2,3,4});
	vector<vector<int>> ans = findSuperset(a);

	for(vector<vector<int>>::iterator it = ans.begin() ; it != ans.end() ; it++){
		cout<<"{ ";
		printVector(*it);
		cout<<"}"<<endl;
	}
}
