//make a linked list api
#include <iostream>
#include <linkedlist.h>

using namespace std;

template<class T>
void reverseLinkedList(linkedListNode<T> **head){
	
	linkedListNode<T> *p1;
	p1 = *head;
	if(p1 == NULL)		//if the list is empty
		return;
	
	linkedListNode<T> *p2 = p1->next;
	if(p2 == NULL)		//if the list is of size one
		return;
	
	linkedListNode<T> *p3 = p2->next;	
	p1->next = NULL;
	p2->next = p1;
	
	if(p3 == NULL){		//if the list is of size two
		*head = p2;
		return;
	}
		
	//start reversing the list iteratively
	while(p3 != NULL){
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
		p2->next = p1;
	}
	*head = p2;
	return;
}

int main(){
	
	linkedListNode<int> *h1=NULL;
	
	//intialise the two test lists
	for(int i=0 ; i <20 ; i++)
		pushNode(&h1, 2*i);
		
	cout<<"List 1 is : ";
	printLinkedList(h1);
	
	cout<<endl;
	cout<<sizeLinkedList(h1);
	cout<<endl;
	
	reverseLinkedList(&h1);
	cout<<"List 1 after reversal is : ";
	printLinkedList(h1);
	cout<<endl;
	
	return 0;
}
