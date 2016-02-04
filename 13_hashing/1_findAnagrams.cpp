#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> findAnagrams(vector<string> stringSet){
	//intitalise and populate the hash map
	typedef unordered_map<string, vector<string>> map1;
	map1 m1;
	for(vector<string>::iterator it = stringSet.begin() ; it != stringSet.end() ; it++){
		string sortString = *it;
		sort(sortString.begin() , sortString.end());
		m1[sortString].push_back(*it);
	}

	//count and check anagrams
	vector<vector<string>> answer;
	for(map1::iterator it = m1.begin() ; it != m1.end() ; it++){
		if((it->second).size() > 1)
			answer.push_back(it->second);
	}
	return answer;
}

int main(){
	vector<string> a({"hello","fsdg","world","gdsf","goku","kogu","elloh"});
	vector<vector<string>> answer = findAnagrams(a);

	for(vector<vector<string>>::iterator i1 = answer.begin() ; i1 != answer.end() ; i1++){
		for(vector<string>::iterator i2 = i1->begin() ; i2 != i1->end() ; i2++)
			cout<<*i2<<" ";
		cout<<endl;
	}
	return 1;
}