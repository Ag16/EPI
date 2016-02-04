//program to delete all b's and replace each a by d din agiven string using no extra space
#include <iostream>
#include <string>

using namespace std;

void modifyString(string &s){
	//remove all the 'b's
	int c1=0,c2=0;
	for(int i=0 ; i<s.length() ; i++){
		if(s[i] == 'b'){
			c1++;
		}
		else{
			if(s[i] == 'a')
				c2++;
			s[i-c1] = s[i];
		}
	}
	s.resize(s.size() - c1);
	
	//insert spaces in the end
	s.insert(s.end(),c2,' ');
	
	//perform the backwards iteration
	int k=s.size() - 1;
	int i = s.size()-1-c2;
	
	while(c2 != 0){
		//swap s[i] with s[k]
		s[k] = s[i];
		s[i] = ' ';
		k--;
		i--;
		
		//case when we encountered an 'a'
		if(s[k+1] == 'a'){
			s[k+1] = 'd';
			s[k] = 'd';
			k--;
			c2--;
		}
	}
}

int main(){
	string s;
	cin>>s;
	modifyString(s);
	cout<<s<<endl;
}
