//program to print the reverse anticlockwise spiralling order of a matrix, starting from top right

#include <iostream>
using namespace std;

#define MAX 100

void printClock(int a[MAX][MAX], int &x, int &y, int r, int c){
	int i,j;
	if(c == 1){
		for(i=0 ; i<r ; i++)
			cout<<a[x-i][y]<<" ";
		x-= (r-1);
	}
	else if(r == 1){
		for(j=0 ; j<c ; j++)
			cout<<a[x][y-j]<<" ";
		y -= (c-1);
	}
	else{
		for(i=0 ; i<=r-2 ; i++)
			cout<<a[x+i][y]<<" ";
		for(j=1 ;j<=c-1 ; j++)
			cout<<a[x+r-2][y+j]<<" ";
		for(i=r-3 ; i>= -1 ; i--)
			cout<<a[x+i][y+c-1]<<" ";
		for(j=c-2 ; j>= 0 ; j--)
			cout<<a[x-1][y+j]<<" ";
		x -= 1;
	}
}

void printReverseAnticlock(int a[MAX][MAX], int r, int c){
	int ch,t,d;
	if(r>c){
		ch = 1;
		t = c;
	}
	else{
		ch = 2;
		t =r;
	}
	
	int x,y;
	d = (t%2 == 0)?2:1;
	cout<<d<<endl;
	int h = r-t+d, b = c-t+d;
	int k = (t-d)/2;
	
	if(ch == 2){
		x = r/2;
		if(h == 1)
			y = c-1-k;
		else
			y = k;
	}
	else{
		y = c/2;
		if(b == 1)
			x = r-1-k;
		else
			x = k;
	}
	
	while(y >= 0){
		printClock(a,x,y,h,b);
		y--;
		b += 2;
		h += 2;
	}
	
}

int main(){
	int a[MAX][MAX];
	int r, c;
	int k=1;
	cout<<"Enter r and c : ";
	cin>>r>>c;
	
	for(int i=0 ; i<r ; i++){
		for(int j=0 ; j<c ; j++){
			cout<<k<<"\t";
			a[i][j] = k++;
		}
		cout<<endl;
	}
			
	printReverseAnticlock(a,r,c);
	cout<<endl;
}
