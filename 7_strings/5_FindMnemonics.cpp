#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printMnemonicsUtil(string s, int n, int i, vector<string> &map){
	//fucntion assumes correct input
	
	static string ans;
	
	//base case we print the answer string in this case
	if(i >= n){
		cout<<ans<<endl;
		return;
	}	
	
	int d = s[i] - '0' - 2;
	//for each possiblity coressponding to this letter add to the answer and  make a recursive call
	for(string::iterator it = map[d].begin() ; it!= map[d].end() ; it++){
		//add this letter to the answer string
		ans.push_back(*it);
		//make the recursive call
		printMnemonicsUtil(s,n,i+1, map);
		//remove this letter from the answer string to make way for the other mnemonics
		ans.erase(ans.end()-1);
	}
	return;
}

void printMnemonics(string s){
	vector<string> map;
	map.push_back("ABC");
	map.push_back("DEF");
	map.push_back("GHI");
	map.push_back("JKL");
	map.push_back("MNO");
	map.push_back("PQRS");
	map.push_back("TUV");
	map.push_back("WXYZ");
	
	printMnemonicsUtil(s, s.size(), 0, map);
}

int main(){
	cout<<"Enter the string (it should only contain digits from 2 to 9) :"<<endl;
	string s;
	cin>>s;
	printMnemonics(s);
}
