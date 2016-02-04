//program to check pallindromes on removal of all nonalphanumeric characters from the string
#include <iostream>
#include <string>

using namespace std;

inline bool isAlphaNumeral (char c){
	return ((c >= 'a' && c <= 'z') || (c>= 'A' && c<='Z') || (c>='0' && c<='9'));
}

inline char toLowerCase(char c){
	if(c >= 'A' && c <= 'Z')
		c = c - 'A' + 'a';
	return c;
}

bool checkPallindrome(string s){
	int i=0, j= s.size()-1;
	while(i<j){
		while(!isAlphaNumeral(s[i]))
			i++;
		while(!isAlphaNumeral(s[j]))
			j--;
		
		//check again if vertices are such that i<i
		if(i >= j)
			break;
		
		if(toLowerCase(s[i]) == toLowerCase(s[j])){
			i++;
			j--;
		}
		else
			return false;
	}
	return true;
}

int main(){
	string s;
	cout<<"Enter the string : "<<endl;
	getline(cin,s);
	if(checkPallindrome(s))
		cout<<"The string is a pallindrome"<<endl;
	else
		cout<<"The string is not a pallindrome"<<endl;
	return 0;
}
