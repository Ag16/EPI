//make a linked list api
#include <iostream>
#include <linkedlist.h>

using namespace std;

template<class T>
void evenOddMerge(linkedListNode<T> *head){
	linkedListNode<T> *e, *o, *firstOdd;
	//counting starts from 0 so the head node is even
	e = head;
	o = e->next;
	firstOdd = o;


	while(e && o && o->next){
		e->next = o->next;
		o->next = o->next->next;
		e = e->next;
		o = o->next;
	}
	e->next = firstOdd;
}

int main(){
	
	cout<<"--------------------------------------------------------------------------------------"<<endl;
	linkedListNode<int> *h1=NULL;
	
	for(int i=0 ; i<6 ; i++)
		appendNode(&h1,i);

	/*
	appendNode(&h1, 0);
	appendNode(&h1, 0);
	appendNode(&h1, 3);
	appendNode(&h1, 3);
	appendNode(&h1, 3);
	appendNode(&h1, 3);
	appendNode(&h1, 3);
	appendNode(&h1, 4);
	appendNode(&h1, 5);
	appendNode(&h1, 5);
	appendNode(&h1, 6);
	appendNode(&h1, 7);
	appendNode(&h1, 8);
	appendNode(&h1, 8);
	appendNode(&h1, 9);
	
	*/
	cout<<"List 1 is :"<<endl;
	printLinkedList(h1);
	cout<<endl;

	evenOddMerge(h1);
	cout<<"List 1 after even-odd merge is : "<<endl;
	printLinkedList(h1);
	cout<<endl<<"--------------------------------------------------------------------------------------"<<endl;
	return 0;
}
