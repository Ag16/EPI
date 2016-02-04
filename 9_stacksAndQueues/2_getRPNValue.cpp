//make a linked list api
#include <iostream>
#include <stack>

using namespace std;

int getNum(string n, int s, int e){
	int num = 0;
	for(int i=s ; i<=e ; i++){
		num *= 10;
		num += n[i]-'0';
	}
	return num;
}

inline bool isOperator(char c){
	return c=='+' || c=='-' || c=='/' || c=='*';
}

int performOperation(char c, int a, int b){
	int n;
	switch(c){
		case '+' : 
			n = a+b;
			break;
		case '-' :
			n = a-b;
			break;
		case '*':
			n = a*b;
			break;
		case '/':
			n = a/b;
			break;
		default:
			n = 0;
			break; 
	}
	return n;
}

int getRPNVal(string exp){
	//the string will contain the rpn expressions in a comma separated list
	stack<int> a;
	int o1,o2;
	//read this from left to right processing the operands and operators as they come
	int i=0,j, l=exp.size();
	while(i<l){
		//case when we have reached an operator
		if(isOperator(exp[i])){
			o1 = a.top();
			a.pop();
			o2 = a.top();
			a.pop();
			a.push(performOperation(exp[i],o2,o1));
			i += 2;		//skip the comma that follows and go to the next location containing an operator or operand
		}
		else{
			//case when we are on an operand
			j = i+1;
			while(exp[j] != ',')
				j++;
			int temp = getNum(exp,i,j-1);
			a.push(temp);	 
			i = j+1;	//goto the next term
		}
	}
	return a.top();
}

int main(){
	cout<<"Enter the expression with terms separated by commas : ";
	string exp;
	cin>>exp;

	cout<<getRPNVal(exp)<<endl;

	return 0;
}