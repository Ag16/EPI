//make a linked list api
#include <iostream>
#include <stack>

using namespace std;

template <class T>
class maxStack{
	stack<T> a;
	stack<T> max;

public:
	maxStack():a(),max(){
	}

	void push(T d){
		a.push(d);
		if(max.empty() || max.top() <= d)
			max.push(d);
	}

	bool getMax(T &x){
		if(!max.empty())
			x =  max.top();
		else{
			x = T();
			cout<<"The stack is empty"<<endl;
			return false;
		}
	}

	bool top(T &x){
		if(!a.empty()){
			x =  a.top();
			return true;
		}
		else{
			x = T();
			cout<<"The stack is empty"<<endl;
			return false;
		}
	}

	void pop(){
		if(!a.empty()){
			if(a.top() >= max.top()){
				a.pop();
				max.pop();
			}
		}
		else
			cout<<"The stack is empty";
	}
};

int main(){
	maxStack<int> s1;
	int m;

	if(s1.top(m))
		cout<<m<<endl;
	
	s1.push(2);
	s1.push(2);
	

	if(s1.top(m))
		cout<<m<<endl;
	

	if(s1.getMax(m))
		cout<<m<<endl;

	s1.push(1);
	if(s1.getMax(m))
		cout<<m<<endl;

	s1.push(5);
	if(s1.getMax(m))
		cout<<m<<endl;

	return 0;
}