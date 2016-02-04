#include <iostream>

using namespace std;

string lookAndSayRecursive(int n);
string lookAndSayRecursiveUtil(string s, int n, int k);

int main() {
    cout<<"Enter n : ";
    int n;
    cin>>n;
    cout<<lookAndSayRecursive(n)<<endl;
    return 0;
}

string lookAndSayRecursive(int n){
    string s = "1";
    return lookAndSayRecursiveUtil(s,n,2);
}

string lookAndSayRecursiveUtil(string s, int n, int k){
    if(k > n)
        return s;

    char d;
    int c;
    string t;
    for(int i=0 ; i<s.size() ; i++){
        d = s[i];
        c = 1;
        while(i<s.size() && s[i] == s[i+1]) {
            c++;
            i++;
        }
        t.push_back((char)c+'0');
        t.push_back(d);
    }

	return lookAndSayRecursiveUtil(t,n,k+1);
}
