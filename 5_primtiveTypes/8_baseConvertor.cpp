/*Program to convert a number of base b1 to base b2*/
#include <iostream>
#include <string>

using namespace std;

string b1Tob2(string s, int b1, int b2);
long int b1ToTen(string s, int b1);
string tenTob2(long int num, int b2);
string reverseString(string s);

int main(){
	string s;
	int b1, b2;
	cin>>s>>b1>>b2;
	s = b1Tob2(s,b1,b2);
	cout<<s<<endl;
	return 0;
}

string b1Tob2(string s, int b1, int b2){
	long int num;
	num = b1ToTen(s, b1);
	s = tenTob2(num, b2);
	return s;
}

long int b1ToTen(string s, int b1){
	long int result = 0;
	char c;
	int r;
	bool isNegative = false;
	string::iterator it = s.begin();
	
	if(*it == '-'){
		isNegative = true;
		it++;
	}

	for(;it != s.end() ; it++){
		c = *it;
		if(c <= '9' && c >= '0')
			r = c - '0';
		else
			r = c - 'A'  + 10;

		result *= b1;
		result += r;
	}
	return result;
}


string tenTob2(long int num, int b2){
	char c;
	int r;
	string s;
	bool isNegative = false;

	if(num < 0){
		isNegative = true;
		num *= -1;
	}

	while(num){
		r = num % b2;
		if(r <= 9)
			c = '0' + r;
		else
			c = r - 10 + 'A';

		s.push_back(c);
		num /= b2;
	}
	if(isNegative)
		s.push_back('-');
	s = reverseString(s);
	return s;
}

string reverseString(string s){
	string::iterator i,ir;
	char temp;
	i = s.begin();
	ir = s.end()-1;
	for(; i<ir ; i++, ir--){
		temp = *i;
		*i = *ir;
		*ir = temp;
	}
	return s;
}