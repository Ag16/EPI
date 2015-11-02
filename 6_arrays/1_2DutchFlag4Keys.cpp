/*implementation of the dutch national flag algorithm but with 4 colours*/

#include <iostream>
#include <string>

#define MAX_SIZE 100
using namespace std;

void swap(string &a, int x, int y){
	char t = a[x];
	a[x] = a[y];
	a[y] = t;
	return;
}

int main(){
	//0 - a-1 : 0
	//a - b-1 : 1
	//b - c-1 : 2
	//c - d : ?
	//d+1 - the end: 3
	int a,b,c,d;
	a=b=c=0;
	string s;
	cin>>s;
	d = s.length() - 1;
	
	while(d >= c){
	    switch(s[c]){
		    case '0':
			    swap(s,b,a);
			    swap(s,a,c);
			    b++;
			    a++;
			    c++;
			    break;
		    case '1':
			    swap(s,b,c);
			    c++;
			    b++;
			    break;
		    case '2':
		        c++;
		        break;
		    case '3':
                while(s[d] == '3')
                    d--;
                if(d < c)
                    break;
                swap(s,c,d);
                d--;
                break;
        }		
	}
	cout<<s<<endl;
	return 0;
}
