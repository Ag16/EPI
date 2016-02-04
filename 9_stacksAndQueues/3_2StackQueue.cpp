//implement two stack queue
#include <iostream>
#include <stack>

using namespace std;


template <class T> class doubleStackQueue{
	stack<T>s1;
	stack<T>s2;
public:
	void enqueue(T o1);
	void dequeue();
	T top();
};

//The logic is that the queue maybe in one of two states depending on whicj one of s1 and s2 is empty
//if s2 is empty, then the queue is in O(n) dequeue and O(1) enqueue mode
//if s1 is empty, then the queue is in O(1) dequeue and O(n) enqueue mode

template <class T>
void doubleStackQueue<T>::enqueue(T o1){
	if(s2.empty())
		s1.push(o1);
	else{
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
		s1.push(o1);
	}
}

template <class T>
void doubleStackQueue<T>::dequeue(){
	if(s1.empty() && s2.empty())
		return;

	if(s1.empty())
		s2.pop();
	else{
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
	}
}

template <class T>
T doubleStackQueue<T>::top(){
	if(s1.empty() && s2.empty()){
		cout<<endl<<"The queue is empty"<<endl;
		exit(1);
	}

	if(s1.empty())
		return s2.top();
	else{
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		return s2.top();
	}
}

int main(){
	doubleStackQueue<int> q1;
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);

	cout<<q1.top()<<endl;

	q1.dequeue();
	cout<<q1.top()<<endl;

	q1.enqueue(5);
	cout<<q1.top()<<endl;

	q1.dequeue();
	q1.dequeue();
	q1.dequeue();
	cout<<q1.top()<<endl;
	q1.dequeue();
	cout<<q1.top()<<endl;

}