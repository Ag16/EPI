#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <limits>

using namespace std;

int LCS(vector<int> A){
	int l = A.size();
	int D[l];	//D[i] is the value of LCS for elements 0 to i, with i included
	int prev[l]; //holds the position of previous element in LCS ending at A[i]. contains -1 for first element

	int maxTillNow, prevTemp;
	int max=0, maxIndex=0;

	for(int i=0 ; i<l ; i++){
		maxTillNow = 1;
		prevTemp = -1;

		for(int j=0 ; j<i ; j++){
			if(A[i]>A[j] && D[j]+1 > maxTillNow){
				prevTemp = j;
				maxTillNow = D[j]+1;
			}
		}

		D[i] = maxTillNow;
		prev[i] = prevTemp;
		if(maxTillNow > max){
			max = maxTillNow;
			maxIndex = i;
		}
	} 

	//print the LCS
	int idx = maxIndex;
	stack<int> ans;
	while(idx >=0){
		ans.push(A[idx]);
		idx = prev[idx];
	}
	while(!ans.empty()){
		cout<<ans.top()<<" ";
		ans.pop();
	}
	cout<<endl;

	return max;
}

int main(){
	vector<int> A({0,8,4,12,2,10,6,14,1,9});
	cout<<LCS(A)<<endl;
	return 0;	
}