//implement run length encoding decoding
#include <iostream>
#include <string>

using namespace std;

string encodeRunLength(string s);
string decodeRunLength(string s);

int main(){
	string s;
	int choice;
	
	while(1){
		cout<<"1. Encode\n2. Decode\n3. Exit\n";
		cout<<"Enter choice : ";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter the string : "<<endl;
				cin>>s;
				cout<<encodeRunLength(s);
				cout<<endl<<endl;
				break;
			case 2:
				cout<<"Enter the string : "<<endl;
				cin>>s;
				cout<<decodeRunLength(s);
				cout<<endl<<endl;
				break;
			case 3:
				cout<<endl;
				return 1;
				break;
			default:
				cout<<"Enter a valid choice!"<<endl;
				cout<<endl<<endl;
		}
	}
	return 0;
}

string decodeRunLength(string s){
	string ans;
	int d;
	char c;
	for(int i=0 ; i<s.size() ; i+=2){
		d = s[i] - '0';
		c = s[i+1];
		for(int j=0 ; j<d ; j++)
			ans.push_back(c);
	}
	return ans;
}

string encodeRunLength(string s){
	char c;
	string ans;
	int i =0,count =0;
	
	while(i < s.length()){
		c = s[i];
		count =1;
		while(i < s.length() && s[i] == s[i+1]){
			count++;
			i++;
		}
		ans.push_back((char)count + '0');
		ans.push_back(c);
		i++;
	}
	return ans;
}
