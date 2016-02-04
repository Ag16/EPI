//to implement algorithms that check for a given substring inside a sttring
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long int robinCarpSubstringSearch(string s, string pat);
long int kmpSearch(string s, string pat);
void createLPS(string pat, vector<int> &lP);

int main(){
	string s,pat;
	cout<<"Enter s and pat : "<<endl;
	getline(cin,s);
	getline(cin,pat);
	
	int pos = kmpSearch(s,pat);
	cout<<"pos = "<<pos<<endl;
	return 0;
}

long int robinCarpSubstringSearch(string s, string pat){
	
	return 0;
}

long int kmpSearch(string s, string pat){
	vector<int> lp(pat.size(),-1);
	createLPS(pat,lp);
	
	long int pos = -1;
	int k =0,i=0;
	int l1 = s.size(), l2 = pat.size();
	
	while(i<l1){
		if(s[i] == pat[k]){
			k++;
			i++;
		}
		
		if(k == l2){
			pos = i - l2 + 1;
			break;
		}
		
		if(s[i] != pat[k]){
			if(k != 0)
				k = lp[k-1];
			else
				i++;
		}
	}
	return pos;
}

void createLPS(string pat, vector<int> &lp){
	lp.clear();
	lp.push_back(0);
	int i=1, k=0;
	int l1 = pat.size();
	
	while(i < l1){
		if(pat[i] == pat[k]){
			k++;
			lp.push_back(k);
			i++;
		}
		else{
			if(k != 0)
				k = lp[k-1];
			else{
				lp.push_back(k);
				i++;
			}
		}
	}
}


	
