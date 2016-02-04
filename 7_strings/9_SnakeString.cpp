//write a function that returns the snake string

#include <iostream>
#include <string>

using namespace std;

string snakeString(string s){
	string ans;
	
	for(int i=1 ; i<s.size() ; i+=4)
		ans.push_back(s[i]);
	
	for(int i=0 ; i<s.size() ; i+=2)
		ans.push_back(s[i]);
	
	for(int i=3 ; i<s.size() ; i+=4)
		ans.push_back(s[i]);
	
	return ans;
}

int main(){
	cout<<"Enter the string : "<<endl;
	string s;
	getline(cin,s);
	cout<<snakeString(s);
	return 0;
}
