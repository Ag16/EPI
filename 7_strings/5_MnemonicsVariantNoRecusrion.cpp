//solve the mnemonics problem wihtout the use of precursion

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

void findMnemonics(string s){
    if(s.empty())
        return;
    
    //initialise tha map that contains the characters for each dogit
    vector<string> map;
    map.push_back("ABC");
    map.push_back("DEF");
    map.push_back("GHI");
    map.push_back("JKL");
    map.push_back("MNO");
    map.push_back("PQRS");
    map.push_back("TUV");
    map.push_back("WXYZ");
    
    int l = s.size();
    
    queue<string> q;
    //intialise the queue
    int d = s[0] - '2';
    for(string::iterator it = map[d].begin() ; it != map[d].end() ; it++){
        string temp;
        temp.push_back(*it);
        q.push(temp);
    }
    string t;    
    int i = 1;
    do{
    t = q.front();
    q.pop();
    
    i = t.size();
    if(i == l)
        cout<<t<<endl;
    else{
        d = s[i] - '2';
        for(string::iterator it = map[d].begin() ; it != map[d].end() ; it++){
            string temp(t);
            temp.push_back(*it);
            q.push(temp);
        }
    }
    }while(!q.empty());
}

int main(){
    cout<<"Enter the string of digits ranging from 2 to 9 :"<<endl;
    string s;
    cin>>s;
    findMnemonics(s);
    return 0;
}

