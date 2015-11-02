/*implement big integer increment operation in c++*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class bigInteger{
	vector <int> a;
	int size;
	
	public:
	void initiateInteger();
	void printInteger();
	void incrementInteger();
};

void bigInteger::initiateInteger(){
	cout<<"Enter the integer"<<endl;
	string s;
	cin>>s;
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
	if(c == 1)
		a.push_back(1);
}

int main(){
	//integer is represented as an array
	//to facilitate in increment where the number of digits increase we shall store the lsb at index 0 and mab at max index
	//a vector intead of an interger is used to be able to insrt additional digits when need be
	
	bigInteger bi;
	bi.initiateInteger();		
	cout<<"The integer is :"<<endl;
	bi.printInteger();
	bi.incrementInteger();
	cout<<"The integer after incrementing is :"<<endl;
	bi.printInteger();
	return 0;
}
