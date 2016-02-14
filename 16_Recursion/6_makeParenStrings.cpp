#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void printMParenStringsUtil(int l, int r, vector<string> &a, string &s){
	if(l==0 && r==0){
		a.push_back(s);
		return;
	}

	if(l>0){
		s.push_back('(');
		printMParenStringsUtil(l-1,r+1, a, s);
		s.pop_back();
	}
	if(r>0){
		s.push_back(')');
		printMParenStringsUtil(l,r-1,a,s);
		s.pop_back();
	}
}

vector<string> printMParenStrings(int n){
	vector<string> a;
	string s;
	printMParenStringsUtil(n,0,a,s);
	return a;
}

template <typename T>
void printVector(const vector<T> &v){
	for(typename vector<T>::const_iterator it = v.cbegin() ; it != v.cend() ; it++)
		cout<<*it<<endl;
}

int main(){
	int n=2;
	vector<string> a = printMParenStrings(n);
	printVector(a);
	return 0;
}
