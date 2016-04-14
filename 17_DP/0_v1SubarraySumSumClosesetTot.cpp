//find the subarray with sum closest to t
#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <cmath>
#include <limits>

using namespace std;

int findClosestTot(vector<int> a, int t){
	set<int> sumTree;
	sumTree.insert(0);
	int sum=0;
	int minSoFar = numeric_limits<int>::max();
	set<int>::iterator x;
	int ans=0;

	for(vector<int>::iterator it = a.begin() ; it  != a.end() ; it++){
		sum += *it;
		x = sumTree.lower_bound(sum-t);
		if(abs(sum-(*x)-t) < minSoFar){
			
			minSoFar = abs(sum-(*x)-t);
			ans = sum-(*x);
cout<<" "<<*it<<" "<<sum<<" "<<*x<<" "<<ans<<endl;
		}
		if(x != sumTree.begin()){
			x--;
			if(abs(sum-(*x)-t) < minSoFar){
				minSoFar = abs(sum-(*x)-t);
				ans = sum-(*x);
cout<<" "<<*it<<" "<<sum<<" "<<*x<<" "<<ans<<endl;
			}
		}
		sumTree.insert(sum);
	}
	return ans;
}

int main(){
	vector<int> a({-4, -2, 3, 4,9,19});
	cout<<findClosestTot(a,18)<<endl;
	return 0;
}


