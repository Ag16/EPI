//circular queue API
//*********NOT TESTED**********

#include <iostream>

using namespace std;

template<class T>
class circularQueue{
	T *a;		//the array that will store the queue
	unsigned long int start;
	unsigned long int end;
	unsigned long int capacity;
public:
	circularQueue(unsigned long int size);		//constructor

	//helper functions
	bool full();
	void enqueue(T o1);
	void dequeue();
	T *front();
	unsigned long int size();
};

template <class T>
circularQueue<T>::circularQueue(unsigned long int size){
	//constructor that takes the size of the queue as input
	a = new T[size + 1];
	capacity = size;
	start = 0;
	end = 0;
}

template <class T>
bool circularQueue<T>::full(){
	//return whether or not the queue is empty
	return (end+1)%(capacity+1) == start;
}

template<class T>
void circularQueue<T>::dequeue(){
	//in case the queue is empty, the function will do nothing
	if(start == end)
		return;

	//otherwise dequeue, removing the element at the front
	start = (start+1) % (capacity+1);		//capacity+1 is the size of the array
	return;
}

template<class T>
T *circularQueue<T>::front(){
	//return the element at start, ie the oldest element
	if(start == end){
		//if the queue is empty raise an error and halt execution
		cout<<endl<<"**Error : the queue is empty, cannot return the front of the queue"<<endl;
		exit(1);
	}

	return a[start];
}

template <class T>
void circularQueue<T>::enqueue(T o1){
	if(!full()){
		//when the queue isn't full as yet
		a[end] = o1;
		end = (end+1)%(capacity+1);
	}
	else{
		//when the queue is already full. we will have to incraese space and use relocation
		unsigned long int c1 = (capacity+1)*3;
		T *temp = new T[c1];

		unsigned long int s1 = 0, e1 = 0;
		//copy old values into the newly allocated memory
		for(unsigned long int i=start ;  i != end ; i = (i+1)%(capacity+1))
			temp[e1++] = a[i];

		//add the new element
		temp[e1++] = o1;

		//update the paramters
		start = s1;
		end = e1;
		capacity = c1-1;
		T *t = a;
		a = temp;
		//delete the old memory allcoated
		delete t;
	}
}

template<class T>
unsigned long int circularQueue<T>::size(){
	if(end >= start)
		return end-start+1;
	else
		return (end+1 + capacity-start+1);
}
