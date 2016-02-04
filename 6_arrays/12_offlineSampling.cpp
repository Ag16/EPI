//Given a list of n distinct numbers, generate a subset of size k where k is an integer
//extra space used should be of order O(1)
//answer is to returned in the array itself

#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a  = b;
	b = temp;
}

int findRandomSet(int *a,int n, int k){
	int t;
	if(n < k)
		return 0;
	
	for(int i=0 ; i<k ; i++){
		t = rand()%(n-i);
		//store the result at the beginning of the array
		swap(a[i], a[t+i]);
	}
	return 1;
}

int main(){
	time_t t1;
	time(&t1);
	srand((unsigned long int)t1);
	int *a, n, k;
	cout<<"Enter the number of elements in the array : ";
	cin>>n;
	a = new int[n];
	
	cout<<"Enter the elements of the array:"<<endl;
	for(int i=0 ; i<n ; i++)
		cin>>a[i];
		
	cout<<"Enter k : ";
	cin>>k;
	
	if(findRandomSet(a,n,k)){
		cout<<"The numbers generated are "<<endl;
		for(int i=0 ; i<k ; i++)
			cout<<a[i]<<" ";
	}
	else
		cout<<"could not generate the numbers as k>n";
	cout<<endl;
	return 1;
}
