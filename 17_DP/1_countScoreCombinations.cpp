#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <limits>

using namespace std;

int countWays(int k, const vector<int> &w){
	int s[k+1];
	s[0] = 1;

	for(int i=1 ; i<=k ; i++){
		s[i] = 0;
		for(vector<int>::const_iterator it = w.cbegin() ; it != w.cend() ; it++){
			if(i - *it >= 0){
				s[i] += s[i - *it];
			}
		}
	}
	return s[k];
}

int main(){
	vector<int> w({3,7});
	countWays(11,w);
	return 0;
}
