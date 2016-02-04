//program to perform TELEX endcoding

#include <iostream>
#include <string>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

unordered_map<char, string> m;

int copyEncoding(string &s, int k){
	char d = s[k];
	int i=0;
	for(string::reverse_iterator rit = m[d].rbegin() ; rit != m[d].rend() ; rit++,i++){
		s[k-i] = *rit;
	}
	return i;
}

void telexEncoding(string &s){
	//first get a count of the number of spaces needed in the end
	int spaces=0, count=0;
	for(int i=0 ; i<s.size() ; i++){
		if(m.find(s[i]) != m.end()){
			spaces += m[s[i]].size() - 1;	//-1 because the character itself will be replaced and hence we need 1 less number of spaces
			count++;
		}
	}

	//insert these spaces at the end of the string
	s.insert(s.end(),spaces,' ');
	//now we do the backwards traversal to make the required modifications
	int k = s.size() - 1;
	int i = s.size() - 1 - spaces;
	int t;

	while(count != 0){
		//swap s[k] and s[i]
		s[k] = s[i];
		s[i] = ' ';
		k--;
		i--;
		
		if(m.find(s[k+1]) != m.end()){
			//call a function that will replace the special character by its name in the indices k+1-(m[s[k+1]].length()-1) to k+1
			t = copyEncoding(s, k+1);
			k -= (t-1);
			spaces -= (t-1);
			count--;
		}
	}	
}


int main(){
	m['!'] = "EXCLAMATION MARK";
	m['?'] = "QUESTION MARK";
	m['.'] = "FULL STOP";
	m[','] = "COMMA";
	
	cout<<"Enter the string s : "<<endl;
	string s;
	getline(cin,s);
	
	telexEncoding(s);
	cout<<s<<endl;
}
