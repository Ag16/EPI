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

template<typename T>
void inplaceMerge(vector<T> &a, vector <T> &b, int al){
	//a is the larger of the two vectors that has empty spaces
	//al is the number of elements in the vector a. There are hence, a.size() - al number of blank spaces in teh vector 
	if(a.size() - al < b.size()){
		cout<<"not enough blank spaces in a"<<endl;
		return;
	}

	int bl = b.size();
	int i=al-1, j=bl-1, p = al+bl-1;
	while(i>=0 || j>=0){
		if(i>=0 && j>=0l){
			if(a[i] > b[j])
				a[p--] = a[i--];
			else
				a[p--] = b[j--];
		}
		else if(i>=0){
			while(i>=0)
				a[p--] = a[i--];
		}
		else if(j>=0){
			while(j>=0)
				a[p--] = b[j--];
		}
	}
	return;
}


int main(int argc, char *argv[]){
	vector<int> a({1,41,60,71,80,-1,-1,-1,-1,-1});

	vector<int> b({2,3,75,89});
	printVector(a);
	printVector(b);

	inplaceMerge(a,b,5);
	printVector(a);
	return 0;
}