//rotate a squeare matrix by 90 degrees to the right
#include <iostream>

#define MAX 100

using namespace std;

void Rotate90Right(int a[MAX][MAX], int s){
	int lim;
	if(s%2 == 0)
		lim = s/2-1;
	else
		lim = s/2;
	
	int n=s, temp;
	int x=0, y=0;
	for(int i=0 ; i<= lim ; i++){
		//rotate shells right by 90 degrees one at a time
		for(int j=0 ; j<=n-2 ; j++){
			temp = a[x][y+j];
			a[x][y+j] = a[x+n-1-j][y];
			a[x+n-1-j][y] = a[x+n-1][y+n-1-j];
			a[x+n-1][y+n-1-j] = a[x+j][y+n-1];
			a[x+j][y+n-1] = temp;
		}
		x++;
		y++;
		n -= 2;
	}
}

void printMatrix(int a[MAX][MAX], int s){
	for(int i=0 ; i<s ; i++){
		for(int j=0 ; j<s ; j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
}

int main(){
	int a[MAX][MAX];
	cout<<"Enter s : ";
	int s;
	cin>>s;
	
	int k = 1;
	for(int i=0 ; i<s ; i++)
		for(int j=0 ; j<s ; j++)
			a[i][j] = k++;
	
	cout<<"Initial : "<<endl;
	printMatrix(a,s);
	cout<<endl;
	
	cout<<"After Rotation : "<<endl;
	Rotate90Right(a,s);
	printMatrix(a,s);
	cout<<endl;
}
