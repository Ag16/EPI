//in an array of unsorted numbers with the single constraint that a[0] >= a[1] && a[n-2] <= a[n]
//write an efficient algorithm to find a local minima

#include <vector>
#include <iostream>

using namespace std;

const double precision = 0.0000000000001;
enum comp {LESSER, EQUAL, GREATER};

comp compare(double a, double b){
	if(a-b > precision)
		return GREATER;
	else if(b-a > precision)
		return LESSER;
	if((a-b <= precision) || (b-a <= precision))
		return EQUAL;
}

double Divide(double a, double b){
	if(b == 0){
		cout<<"Can't divide by 0!"<<endl;
		exit(EXIT_FAILURE);
	}
	else if(a==0)
		return 0;

	double r,l,m=1;
	comp c;

	c = compare(a,b);
	if(c == EQUAL){
		return 1;
	}
	else if(c == GREATER){
		l = 1;
		r = a;
	}
	else{
		l = 0;
		r = 1;
	}

	double mProduct;

	while(compare(l,r) != GREATER){
		m = l + 0.5 * (r - l);

		if(compare(r,l) == EQUAL)
			break;
		
		mProduct = m*b;
		c = compare(mProduct, a);
		
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
	
	int choice = 1;
	while(choice == 1){
		double c,a,b;
		cout<<"Enter a and b : ";
		cin>>a>>b;
		c  = Divide(a,b);
		cout<<c<<endl;
		cout<<"Go again? : ";
		cin>>choice;
	}
	return 0;

}