#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <list>

using namespace std;

template<typename T>
pair<int, int> findMinSeg(vector<T> source){
	unordered_map<T, int> m1;
	pair<int, int> ans(-1,-1);
	int e=0, s=0, l = source.size();
	T se;
	while(e<l && s<=e){
		se = source[e];

		if(m1.find(se) != m1.end()){
			m1[se]++;
			e++;
		}
		else{
			m1[se] = 1;
			//now increment s till the set is minimum possible
			while(s<=e && m1[source[s]] > 1){
				m1[source[s]]--;
				s++;
			}
			//store this as the new min pair
			ans = make_pair(s,e);
			e++;
		}
	}
	return ans;
}

int main(int argc, char *argv[]){
	vector<int> a({1,2,3,3,4,2,1,1,5,6,7,1});
	pair<int, int> ans = findMinSeg(a);
	for(int i=ans.first ; i<=ans.second ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}