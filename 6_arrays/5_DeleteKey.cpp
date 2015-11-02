/*Program to remove all occurances of a key in an array*/
//we will maint a count c of the number of times we have found they while we traverse the array from the beginning to end
//at index i, c is the number of occuranes from 0 to i
//thus we must move a[i] back by c spaces

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int deleteKey(vector<int> &s, int k){
	int count = 0;
	for(unsigned int i =0 ; i<s.size() ; i++){
		if(s.at(i) == k)
			count++;
		else{
			if(i-count >= 0)
				s.at(i - count) = s.at(i);	
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
	
	cout<<"Enter the key : ";
	int key;
	cin>>key;
	int count = deleteKey(a,key);
	cout<<"The key was found "<<count<<" time(s). The array now is :"<<endl;
	for(vector<int>::iterator i = a.begin() ; i != a.end() ; i++)
		cout<<*i<<" ";
	cout<<endl;	
}
