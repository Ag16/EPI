//Parity check problem
//We have to find the parity of a large number of 64 bit numbers
//Since the number of numbers is expected to be very large we are creating a lookup table
//of the parities of numbers 0X0000 to 0XFFFF. It is constructed with a lazy approach
//the 64 bit numbers are broken into four parts whose parities are computed using this
//lookup table and our XORd in the end to find the parity of the number as a whole

#include <iostream>

using namespace std;

int parity[65537];
bool isSet[65337];

int preCalParity(unsigned int x);
int returnParity(unsigned long int x);

int main(){
	
	for(int i = 0 ; i<= 0xFFFF ; i++){
		isSet[i] = false;
	}	

	int numTestCases;
	unsigned long int num;
	cin>>numTestCases;
	for(int i =0 ; i<numTestCases ; i++){
		cin>>num;
		cout<<i+1<<". Parity of "<<num<<" is "<<returnParity(num)<<endl;
	}

return 0;
}

int preCalParity(unsigned int x){
	int p;
	if(!isSet[x]){
		p = 0;
		while(x){
			x = x & (x-1);
			p = p ^ 1;
		}
		parity[x] = p;
		isSet[x] = true;
	}
	else
		p = parity[x];
	return p;
}

int returnParity(unsigned long int num){
	//num is a 64 bit integer
	unsigned int mask = 0XFFFF;
	return (preCalParity((num >> 3*16) & mask) ^ preCalParity((num >>2*16) & mask) ^ preCalParity((num >> 16) & mask) ^ preCalParity(num & mask));
}
