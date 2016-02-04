#ifndef _MINHEAP_H_
#define _MINHEAP_H_

#include <vector>
#include <iostream>

using namespace std;

template <class T> void makeHeapMin(vector<T> &b);		//function to turn b into a heap
template <class T> void heapifyMin(vector<T> &a, int i);	//function to heapifu the given vector, from the given node to the bottom

template <class T>
class min_heap{
	vector<T> a;			//vector to hold the heap

	void swapInternal(T &a, T &b);	//used by memeber functions to swap contents of indices in the vector
	void heapifyInternal(int i);	//used internally by member functions 

public:
	min_heap();			//default constructor
	min_heap(vector<T> b);		//constructor in case a vector is passed to it

	void push(T o1);		//push a new element into the heap
	T min();				//returns the min element of the heap ie its top
	bool pop();				//deltes the top element of the heap
	void printHeap();
	int getSize();
};

template<class T>
void min_heap<T>::printHeap(){
	for(typename vector<T>::iterator it = a.begin() ; it != a.end() ; it++)
		cout<<*it<<" ";

}

template<class T>
int min_heap<T>::getSize(){
	return a.size();
}

template<class T>
min_heap<T>::min_heap(){
	//defalut constructor of the min_heap class
}

template<class T>
min_heap<T>::min_heap(vector<T> b){
	//constructor in case a vector is passed to it
	make_heap(b);
	a = b;
}

template<class T>
void min_heap<T>::push(T o1){
	//public memeber funciton to insert an element in tp the heap
	if(a.empty())
		a.push_back(o1);
	else{
		a.push_back(o1);
		int i = a.size() - 1;	//i is the index of the newest inserted node
		T temp;
		int p = (i-1)/2;		//the parent node of i
		while(p>=0 && a[p] > a[i]){
			//swap parent and i
			temp = a[p];
			a[p] = a[i];
			a[i] = temp;
			//make i the parent node
			i=p;
			p = (i-1)/2;
		}
	}
}

template<class T>
T min_heap<T>::min(){
	//public memeber function returns the top of the heap
	if(a.empty()){
		cout<<endl<<"***Error : The heap is empty. Cannot extract min element***"<<endl;
		exit(1);
	}
	return a.at(0);
}

template<class T>
bool min_heap<T>::pop(){
	//public memeber function to pop the top of the heap
	if(a.empty())
		return false;
	
	a[0] = a[a.size()-1];
	a.pop_back();
	heapifyInternal(0);
	return true;
}

template<class T>
void min_heap<T>::swapInternal(T &a, T &b){
	T temp = a;
	a=b;
	b=temp;
}

template<class T>
void min_heap<T>::heapifyInternal(int i){
	//trickles down the heap starting from element i
	if (i >= a.size()/2)
		return;
	int m;
	int l = a.size();
	T min;
	while(i < l/2){
		m = 0;
		//since i < l/2, the left child will always exist
		//as max i is l/2-1 which is the parent of the l-1th node which we know for a fact exists
		if(a[i] > a[2*i+1]){		//check wiht left child
			min = a[2*i+1];
			m = 1;
		}
		else
			min = a[i];

		if(2*i+2 < l && a[2*i+2] < min){		//check with right child
			min = a[2*i+2];
			m = 2;
		}

		//swap with right child if m = 2 and with the left child if m =1 and stop of m = 0
		if(m == 0)
			break;
		else if(m == 1){
			swapInternal(a[i],a[2*i+1]);
			i = 2*i+1;
		}
		else{
			swapInternal(a[i], a[2*i+2]);
			i = 2*i+2;
		}
	}
}

template<class T>
void heapifyMin(vector<T> &a, int i){
	//trickles down the heap starting from element i
	if (i >= a.size()/2)
		return;
	int m;
	int l = a.size();
	T min;
	while(i < l/2){
		m = 0;
		//since i < l/2, the left child will always exist
		//as max i is l/2-1 which is the parent of the l-1th node which we know for a fact exists
		if(a[i] > a[2*i+1]){		//check wiht left child
			min = a[2*i+1];
			m = 1;
		}
		else
			min = a[i];

		if(2*i+2 < l && a[2*i+2] < min){		//check with right child
			min = a[2*i+2];
			m = 2;
		}

		//swap with right child if m = 2 and with the left child if m =1 and stop of m = 0
		if(m == 0)
			break;
		else if(m == 1){
			swap(a[i],a[2*i+1]);
			i = 2*i+1;
		}
		else{
			swap(a[i], a[2*i+2]);
			i = 2*i+2;
		}
	}
}

template<class T>
void makeHeapMin(vector<T> &b){
	//function that can change a vector into a heap
	int l = b.size();
	for(int i = l/2-1 ; i>=0 ; i--){
		heapifyMin(b,i);		//call heapify for each i	
	}
}

#endif