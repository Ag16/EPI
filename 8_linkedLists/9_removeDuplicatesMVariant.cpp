//make a linked list api
#include <iostream>
#include <linkedlist.h>

using namespace std;

template<class T>
void deleteNodes(linkedListNode<T> *prev, linkedListNode<T> *end){
	linkedListNode<T> *it = prev->next, *t;
	int flag = 1;

	while(flag){
		if(it == NULL || it == end)
			flag = 0;
		t = it->next;
		delete it;
		it = t;
	}
	prev->next = t;
}

template<class T>
void removeDuplicatesM(linkedListNode<T> **head, int m){
	linkedListNode<T> *p1 = *head, *end, *dummy, *prev;
	T val;
	int count;

	//intialise and palce the dummy head node
	dummy = new linkedListNode<T>;
	dummy->a = 0;
	dummy->next = *head;
	prev = dummy;

	while(p1 && p1->next){
		val = p1->a;
		count = 0;

		//count the number of repetitions of the node p1. Also get the pointer to the last node in the repetition
		while(p1 && p1->a == val){
			count++;
			end = p1;
			p1 = p1->next;
		}
		if(count > m){
			deleteNodes(prev, end);		//delete all nodes after prev till end including it
			p1 = prev->next;			//reassign p1
		}
		else{
			prev = end;					//reassign prev as well as p1
			p1 = prev->next;
		}
	}
	//remove the dummy head and update the head node
	*head = dummy->next;
	delete dummy;
	return;
}

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
	
	cout<<"--------------------------------------------------------------------------------------"<<endl;
	linkedListNode<int> *h1=NULL;
	
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
	

	cout<<"List 1 before removing duplicates :"<<endl;
	printLinkedList(h1);
	cout<<endl;

	removeDuplicatesM(&h1,5);
	cout<<"List 1 after removing duplicates : "<<endl;
	printLinkedList(h1);
	cout<<endl<<"--------------------------------------------------------------------------------------"<<endl;
	return 0;
}
