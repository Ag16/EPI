#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <list>

using namespace std;

template<typename T>
void printVector(const vector<T> &a){
	for(typename vector<T>::const_iterator it = a.begin() ; it != a.end() ; it++)
		cout<<*it<<" ";
	cout<<endl;
}

void partitionVector(vector<int> &v){
	//intialist the count vector
	unordered_map<int,int> valCount;
	for(vector<int>::iterator it = v.begin() ; it != v.end() ; it++)
		valCount[*it]++;

	//make the ranges array
	typedef unordered_map<int, pair<int,int>> rMap;
	rMap range;
	int c=0;
	for(unordered_map<int,int>::iterator it = valCount.begin() ; it != valCount.end() ; it++){
		range[it->first] = make_pair(c,c + it->second - 1);
		c = c+it->second;
	}

	pair<int, int> p1;
	int x,num,s,e;
	rMap::iterator itr;
	
	// cout<<valCount.size()<<" "<<range.size()<<endl;
	// for(rMap::iterator it = range.begin() ; it != range.end() ; it++){
	// 	cout<<it->first<<" "<<(it->second).first<<" "<<(it->second).second<<"   "<<valCount[it->first]<<endl;
	//}


	while(!range.empty()){
		itr = range.begin();
		p1 = itr->second;
		num = itr->first;
		s = p1.first;
		e = p1.second;
		//first of p1 is the position of the element that we will consider in the original array
		if(v[s] == num){
			s++;
			if(s > e)
				range.erase(itr);
			else
				(itr->second).first = s;
		}
		else{
			x = v[s];
			swap(v[s],v[range[v[s]].first]);
			range[x].first += 1;
			if(range[x].first > range[x].second)
				range.erase(range.find(x));
		}
	}
}

int main(int argc, char *argv[]){
	vector<int> a({1,5,2,5,3,1,1,7,2,5,2,1,2,3});
	printVector(a);
	partitionVector(a);
	printVector(a);
	return 0;
}