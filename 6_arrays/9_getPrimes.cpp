//find all the prime numbers till n using the seiveing method
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findPrimeNumbers(int n, vector<int> &a);
int printVector(vector <int> a);

int main(){
	int n;
	cout<<"Enter the number n : ";
	cin>>n;
	vector<int> ans;
	findPrimeNumbers(n, ans);
	printVector(ans);
}

int printVector(vector<int> a){
	if(a.empty())
		return 0;

	for(vector<int>::iterator it = a.begin() ; it != a.end() ; it++)
		cout<<*it<<" ";
	cout<<endl;	
	return 1;
}

int findPrimeNumbers(int n, vector<int> &a){
	if(n<=0)
		return 0;
	//intitalise the seive
	int *x = new int[n+1], t;
	x[0] = 0;
	x[1] = 0;
	for(int i=2 ; i<=n ; i++)
		x[i] = i;
	
	int r = sqrt(n);
	
	cout<<r<<endl;
	//seiving commences
	for(int i=0 ; i<=r+1 ; i++){
		if(x[i]){
			t = 2;
			while(x[i] * t <= n)
				x[i * (t++)] = 0;
		}
	}
	
	//copy the prime numbers into the vector a
	for(int i=0 ; i<=n ; i++)
		if(x[i])
			a.push_back(x[i]);
	return 1;
}
