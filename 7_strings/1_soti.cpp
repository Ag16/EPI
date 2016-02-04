#include <iostream>
#include <string>

using namespace std;

long int stoiAg16(string s){
	long int num = 0;
	string::iterator it = s.begin();
	int sign;
	if(*it == '-'){
		it++;
		sign = -1;
	}
	else
		sign = 1;
	
	for(; it != s.end() ; it++){
		num *= 10;
		num += *it-'0';
	}
	return num*sign;
}

int main(){
	string s;
	cout<<"Enter the nubmer : ";
	cin>>s;
	long int num = stoiAg16(s);
	cout<<num<<endl;
	return 0;
}
