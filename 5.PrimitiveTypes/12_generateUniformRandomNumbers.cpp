/*Program to generate a random number between a and b
Program assumes correct input*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>

using namespace std;

int genRand(int a, int b, int n, int *randNumbers);

int main(){
	int a,b;
	int n;		//the number of numbers to be generated
	cin>>a>>b>>n;
	int *randNumbers = new int[n];

	genRand(a,b,n,randNumbers);		//function will store n random numbers between a and b in the array randNumbers

	for(int i=0 ; i<n ; i++)
		cout<<randNumbers[i]<<" ";
	cout<<endl;
	delete randNumbers;
	return 0;
}

int genRand(int a, int b, int n, int *randNumbers){
	time_t t1;		
	time(&t1);	
	srand((unsigned long int) t1);		//seed the random number generator function and use the system clock for the seed

	int num=0;
	int range = b-a+1;					//we will generate random numbers in the range from 0 to range and then return num+a
	
	int numBits = 1;
	int k=2;							
	
	while( k < range-1){					//find minimum numBits such that 2^numBits > range-1. numBits will be number of bits to be used
		k <<=1;
		numBits++;							
	}

	for(int j=0 ; j<n ; j++){				//outermost loop for getting n number of numbers
		do{									//outer loop will keep running if a number >= range is produced as in this case we generate a new number and try again
			num = 0;
			for(int i=0 ; i< numBits ; i++){	//inner loop to generate a k bit random number
				num = num << 1;
				num = num | (rand()%2);
			}
		}while(num >= range);
		randNumbers[j] = num+a;
	}	

}

