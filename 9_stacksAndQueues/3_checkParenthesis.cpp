//make a linked list api
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int getParenthesisType(char c){
	int type;
	switch(c){
		case '(':
			type = 1;
			break;
		case ')':
			type = -1;
			break;
		case '{':
			type = 2;
			break;
		case '}':
			type = -2;
			break;
		case '[':
			type = 3;
			break;
		case ']':
			type = -3;
			break;
		default:
			type = 0;
			break;
	}
	return type;
}

bool isWellFormed(string e){
	//check if the strinig is well formed
	stack<int> s1;
	char c;

	for(string::iterator it = e.begin() ; it != e.end() ; it++){
		c = *it;
		int d = getParenthesisType(c);
		if(d>0)
			s1.push(d);			//case when it is a left parenthesis
		else if (d<0){
			//case when it is a right parenthesis
			if(s1.empty())		//if no left parenthesis has been encountered as yet return false
				return false;

			if(s1.top() + d == 0)		//case when top of the stack matches the present right parenthesis type
				s1.pop();
			else
				return false;			//return false if they don't match
			//in case the character is not a parenthesis, the function returns 0
			//in this case we just scan the next character in the string and proess it
		}
	}
	//we return true if the tack is empty and false otherwise
	return s1.empty();
}

int main(){
	cout<<"Enter the string : ";

	string e;
	cin>>e;
	
	if(isWellFormed(e))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

	return 0;
}