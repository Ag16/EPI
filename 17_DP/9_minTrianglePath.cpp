#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

inline int min(int a, int b){
	return a<b?a:b;
}

void printMinPathTriange(vector<vector<int>> A){
	int n = A.size();
	//assign space for the DP
	int D[n][n];
	//fill the DP
	D[0][0] = A[0][0];		//intialise DP
	for(int i=1 ; i<n ; i++){		//fill the rest of the DP
		D[i][0] = A[i][0] + D[i-1][0];
		for(int j=1 ; j<i ; j++)
			D[i][j] = A[i][j] + min(D[i-1][j-1], D[i-1][j]);
		D[i][i] = D[i-1][i-1] + A[i][i];
	}

	//finding and priting the min path
	int min = D[n-1][0], idx = 0;
	for(int i=1 ; i<n ; i++)
		if(min > D[n-1][i]){
			min = D[n-1][i];
			idx = i;
		}

	int idy = n-1, pidx;
	stack<int> path;
	while(idy > 0){
		if(idx == 0)
			pidx = 0;
		else if(idx == idy)
			pidx = idx-1;
		else{
			if(D[idy-1][idx-1] < D[idy-1][idx])
				pidx = idx - 1;
			else
				pidx = idx;
		}
		path.push(D[idy][idx] - D[idy-1][pidx]);
		idx = pidx;
		idy--;
	}
	//0th row not handled by the loop givne above
	path.push(D[0][0]);

	//printing the answer
	cout<<path.top();
	path.pop();
	while(!path.empty()){
		cout<<" --> "<<path.top();
		path.pop();
	}
	cout<<endl;
}

int main(){
	vector<vector<int>> A;

	A.push_back(vector<int>({3}));
	A.push_back(vector<int>({1,8}));
	A.push_back(vector<int>({9,2,1}));
	A.push_back(vector<int>({0,6,6,-1}));
	A.push_back(vector<int>({2,7,4,1,1}));


	printMinPathTriange(A);
	return 0;
}