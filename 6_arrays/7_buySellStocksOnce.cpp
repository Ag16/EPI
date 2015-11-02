/*Maximum profit problem*/

#include <iostream>

using namespace std;

int findMaxProfit(int *stocks, int n){
	int maxSoFar = -1;
	int maxProfit = 0;
	int i = n-1;
	while(i >= 0){
		if(maxSoFar < stocks[i]){
			maxSoFar = stocks[i];
		}
		else{
			if(maxSoFar - stocks[i] > maxProfit){
				maxProfit = maxSoFar - stocks[i];
			}	
		}
		i--;
	}
	return maxProfit;
}

int main(){
	int *stocks;
	int n;
	
	//take user input
	cout<<"Enter the number of stocks : ";
	cin>>n;
	cout<<"Enter the records :"<<endl;
	stocks = new int[n];
	for(int i=0 ; i<n ; i++){
		cin>>stocks[i];
	}	
	
	cout<<"The maximum profit possible is : "<<findMaxProfit(stocks, n)<<endl;	
	return 0;
}

