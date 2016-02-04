#include <iostream>
#include <vector>

using namespace std;

long int getNumberOfTrees(int n, vector<long int> &mem){
	//function expects uninitialised memmbers of mem to be -1
	if(n == 1 || n == 0)
		return 1;

	long int s = 0,s1,s2;
	for(int i=1 ; i <= n ; i++){
		if(mem[i-1] != -1)
			s1 = mem[i-1];
		else
			s1 = getNumberOfTrees(i-1, mem);
		
		if(mem[n-i] != -1)
			s2 = mem[n-i];
		else
			s2 = getNumberOfTrees(n-i, mem);
		
		s += s1 * s2;
	}
	mem[n] = s;
	return s;
}

int main(){
	int n;
	cout<<"Enter n : ";
	cin>>n;

	vector<long int> mem(n+1,-1);
	cout<<"Number of trees = "<<getNumberOfTrees(n,mem)<<endl;
	return 0;

}
