#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int,int> xy;

//n queen problem
bool checkValid(const xy &pos, const vector<xy> &queens){
	int x = pos.first;
	int y = pos.second;
	int delta;
	for(vector<xy>::const_iterator it = queens.cbegin() ; it != queens.cend() ; it++){
		if(it->first == x || it->second == y)
			return false;		//in the same row or collunm
		delta = x - it->first;
		if(it->second+delta == y || y+delta == it->second)
			return false;		//in the same daigonal
	}
	return true;
}

bool nQueenHelper(vector<xy> &q, int n, int r){
	if(r>=n)
		return true;

	for(int c=0 ; c<n ; c++){
		if(checkValid(make_pair(r,c), q)){
			q.push_back(make_pair(r,c));
			if(nQueenHelper(q,n,r+1))
				return true;
			else
				q.pop_back();	//backtrack
		}
	}
	return false;
}

vector<xy> nQueen(int n){
	vector<xy> queens;
	nQueenHelper(queens,n,0);
	return queens;
}



int main(){
	int n;
	cout<<"Enter n : ";
	cin>>n;

	vector<xy> pos = nQueen(n);
	int c=0;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			//pos stores the queen positions increasing row wise
			if(i == pos[c].first && j == pos[c].second){
				c++;
				cout<<" Q ";
			}
			else
				cout<<" x ";
		}
		cout<<endl;
	}
	return 0;
}
