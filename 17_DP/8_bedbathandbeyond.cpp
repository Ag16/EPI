#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

void printWordDecomposition(const string &w, const unordered_set<string> &dict){
	int l = w.size();
	int D[l];
	string temp;

	for(int i=0 ; i<l ; i++){
		D[i] = 0;
		temp = w.substr(0,i+1);
		if(dict.find(temp) != dict.end()){
			D[i] = i+1;
		}
		else{
			for(int j=0 ; j<i ; j++){
				if(D[j]){
					temp = w.substr(j+1,i-j);
					if(dict.find(temp) != dict.end()){
						D[i] = i-j;
						break;
					}
				}
			}
		}
	}

	//printing the word
	int idx = l-1;
	stack<string> st1;
	while(idx>=0){
		if(!D[idx]){
			cout<<"no breakdown of the string could be found\n";
			return;
		}
		temp = w.substr(idx-D[idx]+1,D[idx]);
		st1.push(temp);
		idx = idx-D[idx];
	}
	while(!st1.empty()){
		cout<<st1.top()<<" ";
		st1.pop();
	}
	cout<<endl;
}

int main(){
	unordered_set<string> dict;
	dict.insert("bed");
	dict.insert("bedb");
	dict.insert("bath");
	dict.insert("and");
	dict.insert("beyond");
	dict.insert("sample");
	dict.insert("words");
	dict.insert("for");
	dict.insert("testing");	
	printWordDecomposition("bedbathandbeyond",dict);
	return 0;
}