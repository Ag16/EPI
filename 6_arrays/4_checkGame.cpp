/*program to find the min number of steps needed to reach then*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int findMinSteps(string s){
	//function returns the min number of steps needed to reach the destination
	//-1 is returned in case we cannot reach the end
	vector<int> a(s.length(), -1);
	*a.begin() = 0;
	int count = 0;
	for(vector<int>::iterator it = a.begin() ; it != a.end() ; it++){
		cout<<*it;
		if(*it == -1){
			break;
		}
		int t = s[count] - '0', i = 1;		
		while(count+i<s.length() && i<=t){
			if(a.at(i+count) > a.at(count)+1 || a.at(i+count) == -1)
				a.at(i+count) = a.at(count)+1;
			i++;
		}
		count++;
	}
	cout<<endl;
	
	return a.back();
}

int main(){
	string s;
	cin>>s;
	cout<<findMinSteps(s)<<endl;
	return 0;	
}
