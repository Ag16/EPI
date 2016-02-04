#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <list>

using namespace std;

template<typename T>
void printVector(const vector<T> &a){
	for(typename vector<T>::const_iterator it = a.begin() ; it != a.end() ; it++)
		cout<<*it<<" ";
	cout<<endl;
}

template<typename T>
void swapNos(T &a, T &b){
	T temp = a;
	a=b;
	b=temp;
}

template <typename T>
int partition(vector<T> &v, int l, int r){
	int p = r;
	int s = l-1, m = l, e = r;

	while(e > m){
		if(v[m]==v[p])
			m++;
		else if(v[m] < v[p]){
			s++;
			swapNos(v[s],v[m]);
			m++;
		}
		else{
			e--;
			swapNos(v[e],v[m]);
		}
	}
	swapNos(v[m],v[p]);
	return m;
}

template <typename T>
void quickSort(vector<T> &v, int l, int r){
	if(l>=r)
		return;
	int p = partition(v,l,r);
	quickSort(v,l,p-1);
	quickSort(v,p+1,r);
	return;
}

bool intervalUnion(pair<int, int> &a, pair<int,int> &b){
	//returns false in case there was nothing in common with the two intervals
	//return true if changes were made. The union interval in this case will be stored in b
	if(a.second < b.first || b.second < a.first)
		return false;

	int s = min(a.first, b.first);
	int e = max(a.second, b.second);
	b = make_pair(s,e);
	return true;
}

void insertInterval(list<pair<int,int>> &day, pair<int,int> &p){
	int sflag = 0;
	list<pair<int,int>>::iterator sit;

	//first check if p is even before the first slot and if it is, simply push it to the front of the lsit
	if(p.second < (day.begin())->first){
		day.push_front(p);
		return;
	}

	for(list<pair<int,int>>::iterator it = day.begin() ; it != day.end() && sflag != 1; it++){
		if(intervalUnion(p,*it)){
			sit = it;
			sflag = 1;
		}
	}

	//if we reached the last element in the previous step without a single interval that had an intersecton with p
	if(!sflag){
		day.push_back(p);
	}
	else{
		list<pair<int,int>>::iterator dit = next(sit,1);		
		while(dit != day.end()){
			if(intervalUnion(*dit,*sit)){
				//union is stored in prev so delete dit
				day.erase(dit);
				dit = next(sit,1);
			}
			else
				break;
		}
	}
}

void printDay(list<pair<int, int>> a){
	for(list<pair<int,int>>::iterator it = a.begin() ; it!=a.end() ; it++)
		cout<<"["<<it->first<<", "<<it->second<<"] ";
	cout<<endl;
}

int main(int argc, char *argv[]){
	int a[] = {-4,-1,0,2,3,6,7,9,11,12,14,17};
	list<pair<int,int>> day;
	int i=0;
	while(i<12){
		day.push_back(make_pair(a[i],a[i+1]));
		i += 2;
	}
	cout<<"Before insertion : ";
	printDay(day);

	pair<int,int> p = make_pair(13,14);
	insertInterval(day,p);
	cout<<"After insertion : ";
	printDay(day);

	return 0;
}