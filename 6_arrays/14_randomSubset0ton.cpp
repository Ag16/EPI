//generate a random subset of numbers of size k from 0 to n-1 for a given n
//using not more than O(k) space

#include <iostream>
//#include <unordered_map>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;
void printVector(vector <int> a){
	for(vector<int>::iterator it = a.begin() ; it != a.end() ; it++)
		cout<<*it<<" ";
	cout<<endl;
}

int trueVal(int k, unordered_map<int, int> &h){
	if(h.find(k) != h.end())
		return h[k];
	else
		return k;
}

vector <int> findSubset(int n, int k){
	int i=0,d;
	unordered_map<int, int> h;
	vector<int> ans;
	while(i<k){
		d = rand() % (n-i) + i;
		ans.push_back(trueVal(d,h));
		h[d] = trueVal(i,h);	
		i++;
	}
	return ans;
}

int main(){
	time_t t1;
	time(&t1);
	srand((unsigned long int) t1);
	int n,k;
	cout<<"Enter n and k : ";
	cin>>n>>k;
	vector<int> randSubset = findSubset(n,k);
	printVector(randSubset);
	return 0;
}

