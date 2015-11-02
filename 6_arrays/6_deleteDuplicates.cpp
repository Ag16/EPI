/*Program to remove all duplicates in a sorted array*/
//we will maintin a count c of the number of repetitions found while we traverse the array from the beginning to end
//at index i, c is the number of repetitions
//thus we must move a[i] back by c spaces

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int deleteKey(vector<int> &s){
	int count = 0;
	for(unsigned int i =0 ; i<s.size() ; i++){
		cout<<s.at(i)<<" "<<i<<" "<<count<<endl;
		s.at(i-count) = s.at(i);
		
		if(i+1 < s.size() && s[i] == s[i+1]){
		while(i < s.size()-1 && s[i] == s[i+1]){
			i++;
			count++;
		}
	}
	}
	//delete the last count numbers
	if(count)
		s.erase(s.end() - count, s.end()); 
	return count;
}

int main(){
	vector <int> a; 
	int n,t;
	cout<<"Enter the number of elements in the array : ";
	cin>>n;
	cout<<"Enter the array elements: "<<endl;
	for(int i=0 ; i<n ; i++){
		cin>>t;
		a.push_back(t);
	}
	
	int count = deleteKey(a);
	cout<<"There were "<<count<<" repetitions. The array now is :"<<endl;
	for(vector<int>::iterator i = a.begin() ; i != a.end() ; i++)
		cout<<*i<<" ";
	cout<<endl;	
}
