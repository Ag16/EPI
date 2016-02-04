//binary search for the first occurance of a key k in a list
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
int getFirstK(vector<T> n, unsigned int s, unsigned int e, T k){
	//function returns the position of the first occurrance of the key k
	//in case the key is not found inthe array -1 is returned by the function
	//this is the reason we have kept the return type to be int and not unsigned int

	int l = s;
	int r = e;
	int result = -1;
	int m;
	while(l <= r){
		m = l + (r-l)/2;
		if(n[m] == k){
			result = m;
			r = m-1;
		}
		else if(n[m] > k)
			r = m-1;
		else
			l = m+1;
	}

	return result;
}

int main(){

	vector<int> a({-14,-10,2,108,108,243,285,285,285,401});
	
	for(vector<int>::iterator it = a.begin() ; it != a.end() ; it++)
		cout<<*it<<" ";
	cout<<endl;


	cout<<"For 0 : "<<getFirstK(a,0,a.size()-1, 0)<<endl;
	cout<<"For -14 : "<<getFirstK(a,0,a.size()-1, -14)<<endl;
	cout<<"For 108 : "<<getFirstK(a,0,a.size()-1, 108)<<endl;
	cout<<"For 109 : "<<getFirstK(a,0,a.size()-1, 109)<<endl;
	cout<<"For 285 : "<<getFirstK(a,0,a.size()-1, 285)<<endl;
	cout<<"For 401 : "<<getFirstK(a,0,a.size()-1, 401)<<endl;
	cout<<"For 403 : "<<getFirstK(a,0,a.size()-1, 403)<<endl;

	return 0;

}