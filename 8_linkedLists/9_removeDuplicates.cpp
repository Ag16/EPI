//make a linked list api
#include <iostream>
#include <linkedlist.h>

using namespace std;

template<class T>
void removeDuplicates(linkedListNode<T> *head){
	T val;
	
	//case when the list is empty
	if(head == NULL)
		return;

	//intitalise iterator
	linkedListNode<T> *it = head, *prev;
	
	while(it && it->next){
		val = it->a;
		prev = it;
		it = it->next;
		//go on deleting duplicates
		while(it != NULL && it->a == val){
			//delete this it node
			prev->next = it->next;
			delete it;
			it = prev->next;
		}
	}
}


int main(){
	
	linkedListNode<int> *h1=NULL;
	
	appendNode(&h1, 0);
	appendNode(&h1, 0);
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
	

	cout<<"List 1 before removing duplicates :"<<endl;
	printLinkedList(h1);
	cout<<endl<<endl;

	removeDuplicates(h1);
	cout<<"List 1 after removing duplicates : ";
	printLinkedList(h1);
	cout<<endl;
	return 0;
}
