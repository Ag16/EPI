/*Program to remove duplicates in a sorted array of elements present more than m times and leave behind min(2,m) repetitions of that element*/
//we will maintin a count c of the number of repetitions found while we traverse the array from the beginning to end
//at index i, c is the number of repetitions
//thus we must move a[i] back by c spaces

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min(int a, int b){
	return (a>b)?b:a;
}

int deleteKey(vector<int> &s, int m){
	int count = 0;
	for(unsigned int i =0 ; i<s.size() ; i++){
		s.at(i-count) = s.at(i);
		
		int k = min(m,2);
		if(i+1 < s.size() && s[i] == s[i+1]){
			int t = 0;
			while(i+t < s.size()-1 && s[i+t] == s[i+t+1])
				t++;
			if(t+1 > m){
				i += (t-k+1);
				count += (t-k+1);
			}
			else{
				int x = 1;
				while(i+1 < s.size() && x++ < t+1){
					i++;
					s.at(i-count) = s.at(i);
				}	
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
	int m;
	cout<<"Enter m :";
	cin>>m;
	cout<<"Enter the array elements: "<<endl;
	for(int i=0 ; i<n ; i++){
		cin>>t;
		a.push_back(t);
	}
	
	int count = deleteKey(a,m);
	cout<<count<<"elements were removed. The array now is :"<<endl;
	for(vector<int>::iterator i = a.begin() ; i != a.end() ; i++)
		cout<<*i<<" ";
	cout<<endl;	
}
