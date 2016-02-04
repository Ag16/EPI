//program to find the given permutaiton of an array using O(1) memory

#include <iostream>
#include <vector>

using namespace std;


int printVector(vector<int>a){
	for(vector<int>::iterator it = a.begin() ; it != a.end() ; it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	return 1;
}

void swap(char &a, char &b){
	char temp = a;
	a = b;
	b = temp;
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int findPermutation(vector<int>p, string &a){
	int i = 0, n = p.size();
	
	while(i != n){
		if(p[i] == i)
			i++;
		else{
			swap(a[i], a[p[i]]);
			swap(p[i], p[p[i]]);
		}
	}
	return 1;
}

int main(){
	string a;
	vector<int> p;
	int x;
	cout<<"Enter the inital string : ";
	cin>>a;
	cout<<"Enter the permutation one digit at a time (string starts from index 0) : ";
	for(int i=0 ; i<a.size() ; i++){
		cin>>x;
		p.push_back(x);
	}
	findPermutation(p,a);
	cout<<"The permutation is :"<<a<<endl;
	return 1;
}


