//To sort a stack
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

template<class T>
void insertSort(stack<T> &st, T o1){
	if(st.empty() || st.top() <= o1)
		st.push(o1);
	else{
		T o2 = st.top();
		st.pop();
		insertSort(st, o1);
		st.push(o2);
	}
}

template<class T>
void sortStack(stack<T> &st){
	if(st.empty())
		return;
	else{
		T o1 = st.top();
		st.pop();
		sortStack(st);
		insertSort(st, o1);
	}
}

template<class T>
void printStack(stack<T> &s1){
	if(s1.empty())
		return;
	else{
		T o1 = s1.top();
		s1.pop();
		printStack(s1);
		cout<<o1<<" ";
		s1.push(o1);
	}
}

int main(){
	stack<int> st;
	st.push(3);
	st.push(1);
	st.push(19);
	st.push(0);
	st.push(-4);
	st.push(500);
	st.push(2);
	st.push(4);
	st.push(1);

	sortStack(st);

	printStack(st);
	cout<<endl;

	return 0;
}