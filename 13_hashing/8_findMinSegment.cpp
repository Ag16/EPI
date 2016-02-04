#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <list>

using namespace std;

pair<int, int> findMinSegStreamIn(stringstream &ss1, vector<string>wordList){
	list<int> posList;
	//intialise the map
	unordered_map<string,list<int>::iterator> m1;
	for(vector<string>::iterator it = wordList.begin() ; it != wordList.end() ; it++)
		m1[*it] = posList.end();

	string t;
	int count = 0, l = wordList.size();
	pair<int,int> ans(-1,-1);

	while(getline(ss1, t, ' ')){
		if(m1.find(t) != m1.end()){
			if(m1[t] != posList.end()){
				//case when the word is not being encountered for the first time
				posList.erase(m1[t]);
			}
			posList.push_front(count);
			m1[t] = posList.begin();
		
			if(posList.size() == l){
				if(ans.first == -1 || (posList.front() - posList.back() < (ans.second - ans.first)))
					ans = make_pair(posList.back(), posList.front());
			}
		}
		count++;
	}
	return ans;
}

pair<int, int> findMinSeg(vector<string> sourceText, vector<string>wordList){
	unordered_map<string, int> m1;
	//intialise the map
	for(vector<string>::iterator it = wordList.begin() ; it != wordList.end() ; it++)
		m1[*it] = 0;

	//get all the words into a vector of strings

	int s=0,e=0,l=sourceText.size();
	string strings,stringe;
	pair<int, int> ans(-1,-1);
	int found = 0;
	int size = wordList.size();

	while(e<l && s<=e){	
		while(e<l && found != size){
			//keep increasing e till found is size or we reach the end of the loop
			stringe = sourceText[e];
			if(m1.find(stringe) != m1.end()){
				m1[stringe]++;
				if(m1[stringe] == 1)
					found++;
			}
			e++;
		}

		while(s<e && found == size){
			if(ans.first == -1 || (ans.second - ans.first > e - s - 1))
				ans = make_pair(s,e-1);
			strings = sourceText[s];
			if(m1.find(strings) != m1.end()){
				m1[strings]--;
				if(m1[strings] == 0)
					found--;
			}
			s++;
		}
	}
	
	return ans;
}


int main(int argc, char *argv[]){
	string source = "Hello this is a sample string that is being written so that we may test the solution to the problem of finding the smallest segment of a text that contains all words from a given set of words";
	vector<string> wordList({"that","test"});
	
	//make string vector of source
	stringstream ss1(source);
	string t;
	vector<string> sourceText;
	while(getline(ss1,t,' '))
		sourceText.push_back(t);
	cout<<source<<endl<<endl;
	
	//Output from string vector function
	
	pair<int,int> ans= findMinSeg(sourceText, wordList);
	int start = ans.first;
	int end = ans.second;
	cout<<"Output from string vector function :"<<endl;
	if(start >=0 && end >=0){
		for(int i=start ; i<=end ; i++)
			cout<<sourceText[i]<<" ";
	}
	else
		cout<<"Wot";

	stringstream ss2(source);
	ans= findMinSegStreamIn(ss2, wordList);
	start = ans.first;
	end = ans.second;
	cout<<endl<<"Output from string stream function :"<<endl;
	if(start >=0 && end >=0){
		for(int i=start ; i<=end ; i++)
			cout<<sourceText[i]<<" ";
	}
	else
		cout<<"Wot";
	cout<<endl;
	return 0;
}