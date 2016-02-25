#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <string>

using namespace std;

inline int min(int a, int b, int c){
	return a<b?(a<c?a:c):(b<c?b:c);
}

int levenshteinDistanceMemEfficient(string s1, string s2){
	//make s2 the smaller string
	if(s1.size() < s2.size()){
		string temp = s1;
		s1=s2;
		s2=temp;
	}

	int size1 = s1.size(), size2 = s2.size();
	int D[size2+1];

	for(int i=0 ; i<=size2 ; i++)
		D[i] = i;

	int i_1_j_1, i_1_j, i_j_1;
	for(int i=1 ; i<=size1 ; i++){
		i_1_j_1 = D[0];
		D[0] = i;
		i_j_1 = i;

		for(int j=1 ; j<=size2 ; j++){
			i_1_j = D[j];
			if(s1[i-1] == s2[j-1])
				D[j] = i_1_j_1;
			else{
				D[j] = 1 + min(i_1_j, i_j_1, i_1_j_1);
			}
			i_1_j_1 = i_1_j;
			i_j_1 = D[j];
		}		
	}
	return D[size2];
}

int levenshteinDistance(string s1, string s2){
	int size1 = s1.size(), size2 = s2.size();
	int D[size1+1][size2+1];

	//intialise the DP
	for(int i=0 ; i<=size2 ; i++)
		D[0][i] = i;
	for(int i=1 ; i<=size1 ; i++){
		D[i][0] = i;
	}

	for(int i=1 ; i<=size1 ; i++){
		for(int j=1 ; j<=size2 ; j++){
			if(s1[i-1] == s2[j-1])
				D[i][j] = D[i-1][j-1];
			else{
				D[i][j] = 1 + min(D[i-1][j], D[i][j-1], D[i-1][j-1]);
			}
		}
	}
	return D[size1][size2];
}

int main(){
	string s1 = "Carthorse";
	string s2 = "Orchestra";
	cout<<levenshteinDistance(s1,s2)<<endl;
	cout<<levenshteinDistanceMemEfficient(s1,s2)<<endl;
}