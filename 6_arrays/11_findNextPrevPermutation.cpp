//compute the next and previous permutations
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getPreviousPermutation(vector<int>a, vector<int> &p);
int getNextPermutation(vector<int>a, vector<int> &n);
void printVector(vector <int>a);

int main(){
	cout<<"Enter the permutation :";
	string ns;
	cin>>ns;
	vector<int>a,p,n;
	
	for(string::iterator it = ns.begin() ; it != ns.end() ; it++)
		a.push_back(*it - '0');

	if(getNextPermutation(a,n)){
		cout<<"The next permutation is : ";
		printVector(n);
	}
	else 
		cout<<"This was the largest possible permutation!";
	
	if(getPreviousPermutation(a,p)){
		cout<<"The previous permutation is : ";
		printVector(p);
	}
	else 
		cout<<"This was the smallest possible permutation!";
	
	return 1;
}

void printVector(vector <int>a){
	for(vector<int>::iterator it = a.begin() ; it != a.end() ; it++)
		cout<<*it<<" ";
	cout<<endl;
}

int getNextPermutation(vector<int>a, vector<int> &n){
	//find the first number breaking an increasing sequence starting from the right
	n = a;
	int i;
	vector<int>::reverse_iterator rit = n.rbegin()+1;
	
	while(rit != n.rend()){

		if(*rit < *(rit-1)){
			//find the first number greater than *it starting from the end
			for(i=0 ; *(a.rbegin() + i) < *rit ; i++)
				;	
			swap(*rit, *(n.rbegin()+i));
			reverse(n.rbegin(), rit);
			break;
		}
		rit++;
	}
	//return 0 is the number is the largest permutation
	if(rit == n.rend())
		return 0;
	else
		return 1;
}

int getPreviousPermutation(vector<int>a, vector<int> &n){
	//find the first number breaking an increasing sequence starting from the right
	n = a;
	int i;
	vector<int>::reverse_iterator rit = n.rbegin()+1;
	
	while(rit != n.rend()){

		if(*rit > *(rit-1)){
			//find the first number greater than *it starting from the end
			for(i=0 ; *(a.rbegin() + i) > *rit ; i++)
				;	
			swap(*rit, *(n.rbegin()+i));
			reverse(n.rbegin(), rit);
			break;
		}
		rit++;
	}
	//return 0 is the number is the largest permutation
	if(rit == n.rend())
		return 0;
	else
		return 1;
}
