/*Program to find the reverse of a decimal nubmer*/

#include <iostream>

using namespace std;

int findReverse(int n);

int main(){
	int num;
	cin>>num;
	cout<<findReverse(num)<<endl;
}

int findReverse(int n){
	int x = 0, r;
	bool isNegative = (n<0);
	if(isNegative)
		n *= -1;
	int base = 10;
	while(n){
		x *= base;
		r = n % base;
		n /= base;
		x += r;
	}
	if(isNegative)
		x *= -1;
	return x;
}