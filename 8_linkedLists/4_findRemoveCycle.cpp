//make a linked list api
#include <iostream>
#include <linkedlist.h>

using namespace std;

template<class T>
linkedListNode<T> *findRemoveLoop(linkedListNode<T> *head){
	int result = 0;
	//return 0 if no loop was found

	linkedListNode<T> *slow, *fast;
	slow = fast = head;

	while(fast != NULL && fast->next != NULL && result == 0){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)
				result = 1;
	}

	if(result == 0)		//result will be zero if a loop was not found
		return 0;

	//now we find the beginning of the 
	slow = head;
	linkedListNode<T> *prev;
	while(slow != fast){
		slow = slow->next;
		prev = fast;
		fast = fast->next;
	}

	//slow points to the head of the loop
	//break the loop
	prev->next = 0;
	return slow;
}
int main(){
	
	linkedListNode<int> *h1=NULL;
	
	//intialise the two test lists
	for(int i=0 ; i <20 ; i++)
		appendNode(&h1, 2*i);
	
	int k = 11;
	linkedListNode<int> *start = h1;
	//get the kth node
	for(int i=1 ; i<k ; i++)
		start = start->next;

	//get to the end of thlist
	linkedListNode<int> *end = h1;
	while(end->next)
		end = end->next;

	//make a loop
	end->next = start;

	//show that a loop is created
	cout<<"To show that there is aloop in the 20 element list we shall print the first 21 elements :\n";
	linkedListNode<int> *it = h1;
	for(int i=0 ; i<21 ; i++){
		cout<<it->a<<" ";
		it = it->next;
	}
	cout<<endl;
	
	it = findRemoveLoop(h1);
	cout<<"List 1 after removal is : ";
	printLinkedList(h1);
	cout<<endl;
	cout<<"The head of the loop was element : "<<it->a;
	cout<<endl;
	return 0;
}
