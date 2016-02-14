#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <limits>

using namespace std;

int findMinDeletions(string s){
	int l = s.size();
	int dp[l][l];

	//we will fill according to the length of subsequence we consider starting from 0 to l
	
	//initialisations for length cases 0
	for(int i=0 ; i<l-1 ; i++){
		dp[i][i] = 0;
		dp[i][i+1] = (s[i]==s[i+1] ? 0 : 1);
	}
	dp[l-1][l-1]=0;

	int j;
	//filling the rest of the dp
	for(int gap=2 ; gap<l ; gap++){
		for(int i=0 ; i<l-gap ; i++){
			j = i+gap;
			if(s[i] == s[j])
				dp[i][j] = dp[i+1][j-1];
			else{
				dp[i][j] = 1 + min(dp[i][j-1], dp[i+1][j]);
			}
		}
	}
	return dp[0][l-1];
}

int main(){
	string s = "geeks";
	cout<<findMinDeletions(s)<<endl;
	return 0;
}