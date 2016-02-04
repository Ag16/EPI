//funciton to compute all IP addresses
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> computeIPs(string s);
void computeIPsUtil(string &s, vector<int> pos, vector<string>&ans); 
void addIP(string s, vector<int>pos, vector<string>&ans);
bool isValid(string s, int a, int e);

int main(){
	string s = "19216811";
	
	
	vector<string> ans = computeIPs(s);
	
	cout<<ans.size()<<endl;
	
	for(vector<string>::iterator it = ans.begin() ; it != ans.end() ; it++)
		cout<<*it<<endl;
	
	return 0;
}

vector <string> computeIPs(string s){
	vector <int>pos;
	pos.push_back(-1);
	vector<string>ans;
	computeIPsUtil(s,pos,ans);
	return ans;
}

void computeIPsUtil(string &s, vector<int>pos, vector <string> &ans){
if(pos.size() == 4){
		if(isValid(s,pos.back()+1,s.size()-1)){
			addIP(s,pos,ans);
			return;
		}
		else
			return;
	}
	else{
		int g = (pos[0] < s.size());
			int p = pos.back();
			for(int i=1 ; i+p < s.size()-1 && i<=3 && isValid(s,p+1, p+i); i++){
					//make calls down the recursion tree
					pos.push_back(p+i);
					computeIPsUtil(s,pos,ans);
					pos.pop_back();
			}
	}
	return;
}

bool isValid(string s, int a, int e){
	if(a < 0 || e < 0 || a > s.length()-1 || e > s.length()-1 || a > e || e-a>2)
		return false;
	if(e-a < 2)
		return true;
	//case when string is of length 3
	int n = 0;
	for(int i=0 ; i< 3 ; i++){
		n *= 10;
		n += s[a+i] - '0';
	}
	if(n > 255)
		return false;
	else
		return true;
}

void addIP(string s, vector<int>pos, vector<string>&ans){
	int k = 1;
	string t;
	for(int i =0 ; i < s.length() ; i++){
		t.push_back(s[i]);
		if(i == pos[k]){
			t.push_back('.');
			k++;
		}
	}
	ans.push_back(t);
}
