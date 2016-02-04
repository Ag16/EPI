#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

inline char toLower(char c){
	if(c>='A' && c<='Z')
		c = c + 'a' - 'A';
	return c;
}

bool canFormLetter(string sourceFile, string letterFile){
	ifstream f1,f2;
	f1.open(sourceFile);
	f2.open(letterFile);
	if(!f1 || !f2){
		cout<<"Please check that both the files exist!"<<endl;
		exit(EXIT_FAILURE);
	}
	char c;
	unordered_map<char, int> m1;
	unordered_map<char, int>::iterator i1;

	//create the map of characters
	while(!f1.eof()){
		f1>>c;				//>> will skip all white space characters
		c = toLower(c);		//ALSO : WE DONT NEED TO WORRY ABOUT BLANK SPACES FROM THE END OF THE FILE EITHER FOR SOME REASON
		i1 = m1.find(c);
		if(i1 == m1.end())
			m1[c] = 1;
		else
			m1[c] += 1;
	}

	//check if the letter can be formed
	while(!f2.eof()){
		f2>>c;
		c = toLower(c);
		i1 = m1.find(c);
		if(i1 == m1.end())
			return false;
		else{
			if(m1[c] > 0)
				m1[c]--;
			else
				return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]){
	if(argc < 3)
		cout<<"please enter the names of the source file and the letter file!";
	else if(canFormLetter(argv[1], argv[2]))
		cout<<"Letter can be formed!"<<endl;
	else
		cout<<"Letter cannot be formed!";
	cout<<endl;
	return 1;
}