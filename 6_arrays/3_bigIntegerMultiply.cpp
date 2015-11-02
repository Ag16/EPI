/*implement big integer increment operation in c++*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class bigInteger{
	vector <int> a;

	public:	
	void initiateInteger();
	void initiateInteger(string s);
	void initiateInteger(bigInteger s);
	void printInteger();
	void incrementInteger();
	friend void multiplyInteger(bigInteger &x, bigInteger &y);
	friend void addInteger(bigInteger &x, bigInteger &y);
};

void bigInteger::initiateInteger(bigInteger y){
	this->a.clear();
	for(vector <int>::iterator i = y.a.begin() ; i != y.a.end() ; i++)
		this->a.push_back(*i);
}
	
void bigInteger::initiateInteger(){
	a.clear();
	string s;
	cin>>s;
	//convert the string into an array containing the big integer
	int size = s.length();
	for(int i=size -1  ; i>=0 ; i--){
		a.push_back((int)(s[i] - '0'));
	}	
}

void bigInteger::initiateInteger(string s){
	a.clear();
	//convert the string into an array containing the big integer
	int size = s.length();
	for(int i=size -1  ; i>=0 ; i--){
		a.push_back((int)(s[i] - '0'));
	}	
}

void bigInteger::printInteger(){
	for(vector<int>::reverse_iterator i = a.rbegin() ; i != a.rend() ; i++)
		cout<<*i;
	cout<<endl; 
}

void bigInteger::incrementInteger(){
	int c = 1;
	for(vector<int>::iterator i = a.begin() ; i != a.end() && c == 1 ; i++){
		*i += 1;
		c = *i / 10;
		*i %= 10;
	}
	if(c == 1){
		a.push_back(1);
	}
}

void addInteger(bigInteger &x, bigInteger &y){
	//add x and y and store the sum in x
	vector <int>::iterator i,j;
	i = x.a.begin();
	j = y.a.begin();
	int carry = 0;
	int t;
	bigInteger sum;
	
	while(i != x.a.end() || j != y.a.end()){
		t = carry;
		if(i != x.a.end()){
			t += *i;
			i++;
		}	
		if(j != y.a.end()){
			t += *j;
			j++;
		}
		//determine carry and then modify t to a single digit and push it into the integer *sum
		carry = t / 10;
		t %= 10;
		sum.a.push_back(t);
	}
	if(carry){
		sum.a.push_back(carry);
	}
	
	//copy sum into x
	x.initiateInteger(sum);
	return;
}

void multiplyInteger(bigInteger &x, bigInteger &y){
	bigInteger z;
	z.initiateInteger("0");
	
	vector<int>::reverse_iterator i;
	i = x.a.rbegin();
	int t,carry = 0;
	int shift = x.a.size() - 1;

	for(;i != x.a.rend();i++){
		//to hold the multiplication of each digit of x with y
		bigInteger s;

		//push 0 into s shift number of times;
		if(shift > 0){
			for(int temp = shift ; temp > 0 ; temp--)
				s.a.push_back(0);
			shift--;
		}
		
		carry = 0;
		//form s
		for(vector<int>::iterator j = y.a.begin() ; j != y.a.end() ; j++){
			t = *i * *j;
			t += carry;
			carry = t / 10;
			t %= 10;
			s.a.push_back(t);
		}
		if(carry)
			s.a.push_back(carry);
			
		//add this s to z
		addInteger(z,s);
	}
	x.initiateInteger(z);
	return;
	
}
int main(){
	//integer is represented as an array
	//to facilitate in increment where the number of digits increase we shall store the lsb at index 0 and mab at max index
	//a vector intead of an interger is used to be able to insrt additional digits when need be
	
	bigInteger b1 = bigInteger();
	cout<<"Enter the first integer :"<<endl;
	b1.initiateInteger();		
	cout<<"The integer is :"<<endl;
	b1.printInteger();
	//b1.incrementInteger();
	//cout<<"The integer after incrementing is :"<<endl;
	//b1.printInteger();
	cout<<"Enter the second integer"<<endl;
	bigInteger b2 = bigInteger();
	b2.initiateInteger();
	cout<<"The second integer is :"<<endl;
	b2.printInteger();
	
	/*addInteger(b1, b2);
	cout<<"The sum of the two is :"<<endl;
	b1.printInteger();
	*/
	
	
	/*
	cout<<"The product of the two is :"<<endl;
	multiplyInteger(b1, b2);
	b1.printInteger();
	*/
	return 0;
}
