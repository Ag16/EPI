//in an array of unsorted numbers with the single constraint that a[0] >= a[1] && a[n-2] <= a[n]
//write an efficient algorithm to find a local minima

#include <vector>
#include <iostream>

using namespace std;

int checkSequence(vector<int>a, int pos){
	//return -1 for decreasing
	//0 for a minima
	//1 for increasing
	//3 if its a maxima of ^ shape

	if(a[pos] == a[pos-1]){
		if(a[pos] <= a[pos+1])
			return 0;
		else
			return -1;
	}
	else if(a[pos-1] < a[pos]){
		if(a[pos] <= a[pos+1])
			return 1;
		if(a[pos] > a[pos+1])
			return 3;
	}
	else{
		if(a[pos] <= a[pos+1])
			return 0;
		else
			return -1;
	}
	return 5;
}



template <typename T>
int findLocalMinima(vector<T> a, unsigned int s, unsigned int e){
	//function returns the position of the first occurrance of the key k
	//in case the key is not found inthe array -1 is returned by the function
	//this is the reason we have kept the return type to be int and not unsigned int

	int l = s+1;		//since the first element can't be the minima, we start with l = s+1
	int r = e-1;		//the last element cant be the valley element
	int m;
	int c;

	while(l <= r){
		m = l + (r-l)/2;
		c = checkSequence(a,m);
		//cout<<l<<" "<<r<<" "<<s<<" "<<e<<" "<<m<<" "<<c<<endl;
		if(c == 0)
			break;
		else if(c == -1)	//go right
			l = m+1;
		else
			r = m-1;
	}

	return m;
}

int main(){

	vector<int> a({12,11,11,10,12,12});
	
	for(vector<int>::iterator it = a.begin() ; it != a.end() ; it++)
		cout<<*it<<" ";
	cout<<endl;

	cout<<endl<<findLocalMinima(a,0,a.size()-1)<<endl;

	return 0;

}