#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <list>

using namespace std;

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

template <typename T>
bool binraySearch(T a, vector<T> *p){
	int l=0, r=p->size()-1;
	int m;
	while(l<=r){
		m = l+(r-l)/2;
		if((*p)[m] == a)
			return true;
		else if(a > (*p)[m])
			l = m+1;
		else
			r = m-1;
	}
	return false;
}

template <typename T>
vector<T> findIntersectionBinarySearch(vector<T> a, vector<T> b){
	vector<T> *p1, *p2, ans;
	
	if(a.size() > b.size()){
		p1 = &b;
		p2 = &a;
	}
	else{
		p1 = &a;
		p2 = &b;
	}
	//smaller vector is in p1. Binary search is on the longer array
	for(typename vector<T>::iterator it = p1->begin() ; it != p1->end() ; it++){
		if(binraySearch(*it, p2))
			ans.push_back(*it);
	}
	return ans;
}

template <typename T>
vector<T> findIntersection(vector<T> a, vector<T> b){
	int i=0,j=0;
	int l1 = a.size(), l2 = b.size();
	vector<T> ans;

	while(i < l1 && j<l2){
		if(a[i] == b[j]){
			ans.push_back(a[i]);
			i++;
			j++;
		}
		else if(a[i] < b[j])
			i++;
		else
			j++;
	}
	return ans;
}

template <typename T>
void printVector(vector<T> v){
	for(typename vector<T>::iterator it = v.begin() ; it != v.end() ; it++)
		cout<<*it<<" ";
	cout<<endl;
}

int main(int argc, char *argv[]){
	vector<int> a({43,65,5,326,7,4,6,1,643,2});
	vector<int> b({1,4});
	quickSort(a,0,a.size()-1);
	quickSort(b,0,b.size()-1);
	printVector(a);
	printVector(b);

	vector<int>d = findIntersection(a,b);
	cout<<"Linear method : ";
	printVector(d);

	cout<<"Binary Search method : ";
	vector<int> c= findIntersectionBinarySearch(a,b);
	printVector(c);
	return 0;
}