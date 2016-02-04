//make a linked list api
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

vector<int> sunsetViewList(vector<int> s){
	vector<int> l;
	for(vector<int>::iterator it = s.begin() ; it != s.end() ; it++){
		while(!l.empty() && *it >= l.back())
			l.pop_back();
		l.push_back(*it);
	}
	return l;
}

int main(){
	vector<int> v1({1,9,2,7,5,3,5,4});

	vector<int> v2 = sunsetViewList(v1);

	for(vector<int>::iterator it = v2.begin() ; it != v2.end() ; it++)
		cout<<*it<<" ";
	
	cout<<endl;
	return 0;
}