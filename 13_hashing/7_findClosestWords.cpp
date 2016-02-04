#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>
#include <sstream>

using namespace std;

int minDiff(string s){
	//s constains the whole paragraph
	//realistically this should be in a file however
	//i just wanted to use stringstream to split a string by spaces and am this using this
	//file io can be very easily introduced into the program
	stringstream ss1(s);
	typedef unordered_map<string, int> map1;
	map1 m1;
	int count = 1;
	int min = numeric_limits<int>::max();
	string t;
	map1::iterator it;
	while(getline(ss1,t,' ')){
		it = m1.find(t);
		if(it == m1.end())
			m1[t] = count++;
		else{
			if(count - m1[t] < min)
				min = count - m1[t];
			m1[t] = count++;
		}
	}

	//return -1 if no two words are the same in the text
	if(min == numeric_limits<int>::max())
		return -1;
	
	return min;
}

int main(int argc, char *argv[]){
	string s = "we will try to find the the difference between the closest two words in this line of text that is stored in this array.";
	cout<<minDiff(s)<<endl;
}