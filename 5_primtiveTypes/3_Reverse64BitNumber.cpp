/*Reversing the bits of a large number of 64 bit numbers
we will craete a lookup table containing the reverse of 16 bit nubmers and use this table to compute the reverse of the 64 bit number in a modular
manner
*/

#include <iostream>
#include <cstdio>
using namespace std;

int reverse[0XFFFF + 1];
bool isSet[0XFFFF + 1];

unsigned int preCompReverse(unsigned int x);
unsigned long int find64bitReverse(unsigned long int a);

int main(){
	for(int i=0 ; i<0XFFFF + 1 ; i++)
		isSet[i] = false;
	printf("%lX\n",find64bitReverse(0XFFFA));
	return 0;
}

unsigned int preCompReverse(unsigned int x){
	if(!isSet[x]){
		unsigned int num = x;
		for(int i=0 ; i<8 ; i++){
			if((x>>i & 1) != (x>>(15-i) & 1)){
				x = x ^ (1<<i | 1<<(15-i));
			}
		}
		isSet[x] = isSet[num] = true;
		reverse[num] = x;
		reverse[x] = num;
	}
	else
		x = reverse[x];
	return x;
}

unsigned long int find64bitReverse(unsigned long int a){
	unsigned long int mask = 0XFFFF;
	
	unsigned long int r1 = preCompReverse(a & mask) & mask;
	unsigned long int r2 = preCompReverse((a>>16) & mask) & mask;
	unsigned long int r3 = preCompReverse((a>>32) & mask) & mask;
	unsigned long int r4 = preCompReverse((a>>48) & mask) & mask;
	return ((r1 << 48) | (r2 << 32) | (r3 << 16) | r4);
	//final answer is formed as
}