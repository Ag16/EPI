//make a linked list api
#include <iostream>
#include <linkedlist.h>

using namespace std;

template <class T>
void pivotList(linkedListNode<T> **head, T k){
	
	//create three lists with dummy heads
	linkedListNode<T> *l, *e, *g;
	l = createNode(0);
	e = createNode(0);
	g = createNode(0);

	linkedListNode<T> *d1=l, *d2 = e, *d3 = g;

	linkedListNode<T> *it = *head;

	while(it){
		if(it->a < k){
			l->next = it;
			l = it;
		}
		else if(it->a == k){
			e->next = it;
			e = it;
		}
		else{
			g->next = it;
			g = it;
		}
		it = it->next;
	}

	//assign NULL to the ends of each list
	l->next = NULL;
	e->next = NULL;
	g->next = NULL;

	//merge the three lists in order
	if(d1->next){
		*head = d1->next;
		delete d1;

		if(d2->next){				//if nodes less than and equal to k exist
			l->next = d2->next;	
			delete d2;
			e->next = d3->next;		//atach list g in the end
			delete d3;
		}
		else{
			l->next = d3->next;
			delete d3;
		}
	}
	else if(d2->next){
		//case when none of the nodes were less than k
		*head = d2->next;
		delete d2;

		e->next = d3->next;
		delete d3;
	}
	else{
		//case when all items are greater than k
		*head = d3->next;
		delete d3;
	}
	return;
}


int main(){
	
	cout<<"----------------------------------------------------------------------------"<<endl;
	linkedListNode<int> *h1=NULL;

	/*
	for(int i=0 ; i<6 ; i++)
		appendNode(&h1,i);
	*/
	
//	appendNode(&h1, 0);
	appendNode(&h1, 1);
	appendNode(&h1, 6);
	appendNode(&h1, 10);
	appendNode(&h1, 11);
	appendNode(&h1, 5);
	appendNode(&h1, 16);
	appendNode(&h1, 10);
	appendNode(&h1, 2);
	appendNode(&h1, 12);
	appendNode(&h1, 10);
	appendNode(&h1, 14);
	appendNode(&h1, 13);
	appendNode(&h1, 2);
	appendNode(&h1, 1);

	cout<<"List 1 is :"<<endl;
	printLinkedList(h1);
	cout<<endl;

	pivotList(&h1, 10);

	cout<<"List 1 is :"<<endl;
	printLinkedList(h1);
	cout<<endl;

	cout<<endl<<"----------------------------------------------------------------------------"<<endl;
	return 0;
}
