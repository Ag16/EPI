//in an array of unsorted numbers with the single constraint that a[0] >= a[1] && a[n-2] <= a[n]
//write an efficient algorithm to find a local minima

#include <vector>
#include <iostream>

using namespace std;

const double precision = 0.0000001;
enum comp {LESSER, EQUAL, GREATER};

comp compare(double a, double b){
	if(a-b > precision)
		return GREATER;
	else if(b-a > precision)
		return LESSER;
	if((a-b <= precision) || (b-a <= precision))
		return EQUAL;
}

double findFloatingPointRoot(double n){
	double r,l,m=-1;
	if(n<=1){
		l = n;
		r = 1;
	}
	else{
		l = 1;
		r = n;
	}
	double mSquared;
	comp c;

	while(compare(l,r) != GREATER){
		m = l + 0.5 * (r - l);

		if(compare(r,l) == EQUAL)
			break;
		
		mSquared = m*m;
		c = compare(mSquared, n);
		
		if(c == EQUAL)
			break;
		else if(c == LESSER)
			l = m;
		else
			r = m;
	}

	return m;
}

int main(){

	vector<int> a({0,1,6,4,3,3,3,3,4,4,3,2,1});
	
	double c,n;
	cout<<"Enter n : ";
	cin>>n;
	c  = findFloatingPointRoot(n);
	cout<<c<<endl;

	return 0;

}