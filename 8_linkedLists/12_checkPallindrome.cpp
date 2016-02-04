//make a linked list api
#include <iostream>
#include <linkedlist.h>

using namespace std;

template <class T> bool checkPal(linkedListNode<T> *head);
template <class T> bool checkPalUtil(linkedListNode<T> **cur, linkedListNode<T> *p, int &cc, int pc);

template <class T>
bool checkPal(linkedListNode<T> *head){
	if(head == NULL || head->next == NULL)
		return 1;

	linkedListNode<T> *cur = head, *p = head->next;
	int cc = 1, pc = 2;
	return checkPalUtil(&cur, p, cc, pc);
}

template <class T> 
bool checkPalUtil(linkedListNode<T> **cur, linkedListNode<T> *p, int &cc, int pc){
	if(p->next == NULL)
		return p->a == (*cur)->a;

	bool a1 = checkPalUtil(cur, p->next, cc, pc+1);
	if(!a1)
		return false;

	*cur = (*cur)->next;
	cc++;

	if(pc < cc)
		return a1;
	return p->a == (*cur)->a;
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
	appendNode(&h1, 2);
	appendNode(&h1, 2);
	appendNode(&h1, 1);
	appendNode(&h1, 5);
	appendNode(&h1, 6);
	appendNode(&h1, 7);
	appendNode(&h1, 7);
	appendNode(&h1, 6);
	appendNode(&h1, 5);
	appendNode(&h1, 4);
	appendNode(&h1, 3);
	appendNode(&h1, 2);
	appendNode(&h1, 1);

	cout<<"List 1 is :"<<endl;
	printLinkedList(h1);
	cout<<endl;

	if(checkPal(h1))
		cout<<"It is a pallindrome";
	else
		cout<<"Not a pallindrome";

	cout<<endl<<"----------------------------------------------------------------------------"<<endl;
	return 0;
}
