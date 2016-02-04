//program to simulate the unix tail comman
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

bool atoi(string a, int &n){
	int t = 0;
	if(a.size() == 0 || a.at(0) == '-')
		return false;
	for(string::iterator it = a.begin() ; it != a.end() ; it++){
		if(*it >= '0' && *it <= '9'){
			t *= 10;
			t += *it - '0';
		}
		else
			return false;
	}
	n = t;
	return true;
}

int main(int argc, char *argv[]){
	stack <char> ans;
	
	if(argc < 2){
		cout<<"Please enter a valid file name"<<endl;
		return 0;
	}

	fstream f1(argv[1], ios::in | ios::ate);
	int linecount = 3;
	int count = 0;
	char c;
	
	//get the number of lines to display in case 
	if(argc > 2){
		if(!atoi(argv[2], linecount)){
			cout<<"Please enter a valid number for line count"<<endl;
			return 0;
		}
	}
	if(linecount <= 0){
		cout<<"Please enter a valid number for line count"<<endl;
		return 0;
	}


	//gotp the last character from the eof
	f1.seekg(-2,ios::end);
	//read 
	
	while(count < linecount){
		
		f1.get(c);
		//check for new line and increase count;
		if(c == '\n')
			count++;
		ans.push(c);
		
		//check if we just read the firs character of the file. If this was the case we need to stop reading
		if(f1.tellg() == 1)
			break;
	
		f1.seekg(-2,ios::cur);
	}
	
	//check if the top of the stack is a newline charcter and remove it if it is that
	if(ans.top() == '\n')
		ans.pop();
	
	while(!ans.empty()){
		cout<<ans.top();
		ans.pop();
	}
	cout<<endl;
	return 0;
}
