//program to reverse all the words in a sentence separated by white spaces

#include <iostream>
#include <string>

using namespace std;

void reverseWord(string &s, int i, int j){
	char temp;
	while(i < j){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

void reverseWords(string &s){
	int i=0, j=0;
	
	while(j < s.size()){
		while(s[j] != ' ' && j < s.size())
			j++;
		//check if j is still within bounds
		if(j >= s.size())
			break;
			
		reverseWord(s, i, j-1);
		i = j+1;
		j++;
	}
	
	//last word will not be reversed
	//i still points to the beginning of the last word
	reverseWord(s,i,s.size()-1);
}

int main(){
	string s;
	cout<<"Enter the string : "<<endl;
	getline(cin,s);
	reverseWords(s);
	cout<<s<<endl;
	return 1;
}


