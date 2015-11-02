/*implementation of the dutch national flag algorithm*/

#include <iostream>
#include <string>

#define MAX_SIZE 100
using namespace std;

void swap(string &a, int x, int y){
	char t = a[x];
	a[x] = a[y];
	a[y] = t;
	return;
}

int main(){
	//0 to l-1 is 0
	//l is the first 1
	//m-1 is the last known 1
	//m-h is unknown
	//h +1 is the first 2
	int l=0,m=0,h,i;
	string a;
	cout<<"Enter the array : and index of the element ";
	cin>>a>>i;
	char c = a[i];
	cout<<"Processing input"<<endl;
	h = a.length()-1;

	while(m <= h){
		if(a[m] == c){ 
			m++;
		}
		else if(a[m] < c){
			swap(a,m,l);
			m++;
			l++;
		}
		else{
			while(a[h]>c)
				h--;
			if(h < m)
				break;
			swap(a,m,h);
			h--;
		}
	}
	cout<<a<<endl;
	return 0;
}