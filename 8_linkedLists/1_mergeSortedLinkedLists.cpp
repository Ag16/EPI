//make a linked list api
#include <iostream>
#include <linkedlist.h>

using namespace std;

//merge linked lists of integer type
void mergeSortedLists(linkedListNode<int> **h1, linkedListNode<int> **h2){
	
	//create a dummy node
	linkedListNode<int> *r = new linkedListNode<int>;
	r->a = 0;
	r->next = NULL;
	
	//create iterators
	linkedListNode<int> *i=r;
	linkedListNode<int> *i1 = *h1;
	linkedListNode<int> *i2 = *h2;
	
	//traverse through the lists and make your list
	while(i1 != NULL || i2 != NULL){
		if(i1 != NULL && i2 != NULL){
			if(i1->a < i2->a){
				i->next = i1;
				i1 = i1->next;
			}
			else{
				i->next = i2;
				i2 = i2->next;
			}
			i = i->next;
		}
		else{
			if(i1 != NULL){
				while(i1 != NULL){
					i->next = i1;
					i1 = i1->next;
					i = i->next;
				}
			}
			else{
				while(i2 != NULL){
					i->next = i2;
					i2 = i2->next;
					i = i->next;
				}
			}
		}	
	}
	//set h1 and h2 to null
	*h1 = r->next;
	*h2 = NULL;
	
	//we must now remove the merged list but without the dummy head node
	delete r;
}


int main(){
	
	linkedListNode<int> *h1=NULL;
	linkedListNode<int> *h2=NULL;
	
	//intialise the two test lists
	for(int i=20 ; i <20 ; i++)
		appendNode(&h1, 2*i);
	
	for(int i=1 ; i< 7 ; i++)
		appendNode(&h2, 3*i);

	cout<<"List 1 is : ";
	printLinkedList(h1);
	cout<<endl;
	cout<<"List 2 is : ";
	printLinkedList(h2);
	cout<<endl;
	 
	//merge and display the lists
	mergeSortedLists(&h1,&h2);
	cout<<"The merged list is : ";
	printLinkedList(h1);
	cout<<endl;
	
	return 0;
}
