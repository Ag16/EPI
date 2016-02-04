//make a linked list api
#include <iostream>
#include <linkedlist.h>

using namespace std;

template<class T>
void reverseSublist(linkedListNode<T> **head, int s, int e){
	if(e-s <= 0 || e<1 || s<1)
		return;	
	if(*head == NULL || (*head)->next == NULL)
			return;
	linkedListNode<T> *p1 = *head, *prev = NULL, *suc, *p2, *p3, *end, *start;
	int pos = 1;	//counting starts from 1 not 0
	while(p1->next != NULL && pos < s){		//if we reach the last node, there will be nothing to reverse. The case when s=the last node does not require us to do anything 
		pos++;
		prev = p1;
		p1 = p1->next;
	}
	if(p1->next == NULL)
		return;

	//swap the first two nodes. since we have already returned for the e==s case, at least one swapping is required
	start = p1;
	p2 = p1->next;
	p1->next = NULL;		//for now it will be set to the node after node number e in the end
	p3 = p2->next;
	p2->next = p1;
	pos++;

	while(pos < e && p3 != NULL){
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
		p2->next = p1;
		pos++;
	}
	suc = p3;
	end = p2;
	if(prev != NULL)	//attach the part before the sublist to node number e
		prev->next = end;
	else
		*head = end;	//this is the case when head was a part of the sublist being reversed
	start->next = suc;		// link node number s to the part after the sublist even if reached the last node suc is NULL, hence this assigment is valid
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
	
	reverseSublist(&h1,1,21);
	cout<<"List 1 after reversal is : ";
	printLinkedList(h1);
	cout<<endl;
	
	return 0;
}
