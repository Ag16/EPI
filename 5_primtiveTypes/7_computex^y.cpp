/* Program to find the exponential power of a nubmer using a recursive approach in conjugation with 
bitwise operators*/
#include <iostream>
#include <cstdio>

using namespace std;

long double findPow(double a, int n);

int main(){
	double a;
	int n;
	cin>>a>>n;
	printf("%Lf\n",findPow(a,n));
}

long double findPow(double a, int n){
	long double result = 1;

	while(n){
		if(n & 1){
			result *= a;
		}
		a *= a;
		n = n>>1;
	}
	return result;
}