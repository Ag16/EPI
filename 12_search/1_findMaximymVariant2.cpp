//in an array of unsorted numbers with the single constraint that a[0] >= a[1] && a[n-2] <= a[n]
//write an efficient algorithm to find a local minima

#include <vector>
#include <iostream>

using namespace std;

int findMaxPoint(vector<int>a);
int findMaxPointUtil(vector<int>a, int r, int l);
int maxValue(vector<int>a, int p1, int p2);
int getType(vector<int> a, int pos);

int getType(vector<int> a, int pos){
	//return 1 for increasing slope
	//2 for decreasing slope
	//3 for a ^ shaped maxima
	//4 for a flat shape where pos-1, pos, pos have equal values
	//5 for a v shaped minima which can never occurr in the present quesion

	if(a[pos-1] < a[pos]){
		if(a[pos] <= a[pos+1])
			return 1;
		else
			return 3;
	}
	else if(a[pos-1] == a[pos]){
		if(a[pos] < a[pos+1])
			return 1;
		else if(a[pos] == a[pos+1])
			return 4;
		else
			return 2;
	}
	else{
		if(a[pos] >= a[pos+1])
			return 2;
		else
			return 5;
	}

	return 0;
}

int findMaxPoint(vector<int>a){
	//there is an increasing sequence follwed by a deacreasing one
	//the size of the array hence must be at least 3
	return findMaxPointUtil(a,1,a.size()-2);
}

int maxValue(vector<int>a, int p1, int p2){
	if(p1 == -1 && p2 == -1)
		return -1;
	else if(p1 == -1)
		return p2;
	else if(p2 == -1)
		return p1;
	else
		return (a[p1]>a[p2]) ? p1 : p2;

	return -1;		//to get rid of the warning reached end of non void function without a return
}

int findMaxPointUtil(vector<int>a, int l, int r){
	if(r<l)
		return -1;
	if(l==r)
		return l;

	else if(r == l+1){
		return (a[l]>a[r]) ? l : r;
	}

	int m = l + (r-l)/2;
	int c = getType(a,m);

	if(c == 1)		//upwards slope
		return findMaxPointUtil(a, m+1,r);
	else if(c == 2)		//downards slope
		return findMaxPointUtil(a,l,m-1);
	else if(c==3)		//its a maxima
		return m;
	else if(c==4)
		return maxValue(a, findMaxPointUtil(a,l,m), findMaxPointUtil(a,m+1,r));
	
	return -1;		//just to get rid of the control reaches end of non void function without return warning
}

int main(){

	vector<int> a({0,1,6,4,3,3,3,3,4,4,3,2,1});
	
	for(vector<int>::iterator it = a.begin() ; it != a.end() ; it++)
		cout<<*it<<" ";
	cout<<endl;

	int c = findMaxPoint(a);
	cout<<endl<<c<<"      "<<a[c]<<endl;

	return 0;

}