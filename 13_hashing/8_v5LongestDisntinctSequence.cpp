#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <list>

using namespace std;

template<typename T>
pair<int, int> findLongestDistinct(vector<T> source){
	unordered_map<T, bool> m1;
	pair <int, int> ans(-1,-1);
	int s=0,e=0,l=source.size();
	T x;
	while(e<l && s<= e){
		x = source[e];
cout<<e<<" "<<x<<" ";
		if(m1.find(x) == m1.end() || m1[x] == false){
cout<<"case 1 : "<<" ";			
			m1[x] = true;
			e++;
		//now if the array terminates here then check if this is the largest subarray
			if(e==l &&  (ans.first == -1 || (ans.second-ans.first < e-s-1))){
					ans = make_pair(s,e-1);
cout<<"Used the end road!"<<" ";
			}
		}
		else{
cout<<"case 2 : ";
			//if this is the new largest set then make this the answer pair
			if(ans.first == -1 || (ans.second-ans.first < e-s-1)){
				ans = make_pair(s,e-1);
cout<<" Storing "<<s<<" "<<e-1<<" | ";
			}
			//take s to the first instance of souce[s] and make s the position after it
			while(source[s] != x && s<=e){
cout<<source[s]<<" ";
				m1[source[s]] = false;
				s++;
			}
			//make s the element after the first instance of x
			s++;
			//m1[x] is already true let it stay true and increment e 
			e++;
		}
cout<<" | "<<s<<" "<<e;
cout<<endl;
	}
	return ans;
}

int main(int argc, char *argv[]){
	vector<int> a({1,2,3,1,4,5,3,5,1,2,3});
	for(vector<int>::iterator i = a.begin(); i != a.end() ; i++)
		cout<<*i<<" ";
	cout<<endl<<endl;
	pair<int, int> ans = findLongestDistinct(a);
	for(int i=ans.first ; i <= ans.second ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}