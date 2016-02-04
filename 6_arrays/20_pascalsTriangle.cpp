#include <iostream>
#include <vector>

using namespace std;

int getPascalsTriangle(int n, vector<int> &a);
int printPascalsTriangle(vector<int> a);

int main(){
    vector<int> a;
    int n;
    cout<<"Enter the size of the triangle : ";
    cin>>n;
    getPascalsTriangle(n, a);
    cout<<"size : "<<a.size()<<endl;
    cout<<"The triangle is"<<endl;
    printPascalsTriangle(a);
    return 1;
}

int printPascalsTriangle(vector<int> a){
	if(a.empty())
		return 0;
	vector<int>::iterator it = a.begin();
	int s = 1,r; 
	while(it != a.end()){
		r = 1;
		
		while(r++ <= s)
			cout<<*(it++)<<" ";
		cout<<endl;
		s++;
	}
	return 1;
}

int getPascalsTriangle(int n, vector<int> &a){
    a.clear();
    if(n < 1)
        return 0;
    a.push_back(1);
    vector<int>::iterator it;
    
    int r=2,i;
    while(r<=n){
        //row number r-1 has r-1 elements
        it = a.end() - (r-1);
        a.push_back(1);
        for(i=0 ; i<r-2 ; i++){
            a.push_back(*it + *(it +1));
            it++;
        }
        a.push_back(1);
        r++;
    }
    return 1;
}
