#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

template <class T> struct linkedListNode{
	T a;
	linkedListNode<T> *next;
};

template <class T> linkedListNode<T> *createNode(T d );

template <class T> void appendNode(linkedListNode<T> **head, T o1);

template <class T> int deleteNodeKey(linkedListNode<T> **head, T o1);

template <class T> int deleteNodePos(linkedListNode<T> **head, int pos);

template <class T> int insertNode(linkedListNode<T> *prevNode, T o1);

template <typename T> void printLinkedList(linkedListNode<T> *head);

template <class T> void pushNode(linkedListNode<T> **head, T o1);

template <class T> unsigned long int sizeLinkedList(linkedListNode<T> *head);

//definitions

template <class T>
linkedListNode<T> *createNode(T d){
	linkedListNode<T> *p = new linkedListNode<T>;
	p->a = d;
	p->next = NULL;
	return p;
}

template <class T>
void pushNode(linkedListNode<T> **head, T o1){
	linkedListNode<T> *temp = new linkedListNode<T>;
	temp->a = o1;
	temp->next = *head;
	*head = temp;
	return;
}

template <class T>
int insertNode(linkedListNode<T> *prevNode, T o1){
	//returns 1 on success and 0 on failiure
	if(prevNode == NULL)
		return 0;
	
	linkedListNode<T> *temp = new linkedListNode<T>;
	temp->a = o1;
	temp->next = prevNode->next;
	prevNode->next = temp;
	return 1;
}

template <class T>
void appendNode(linkedListNode<T> **head, T o1){
	linkedListNode<T> *temp = new linkedListNode<T>;
	temp->a = o1;
	temp->next = NULL;
	linkedListNode<T> *it = *head;
	
	//case when the list is empty
	if(it == NULL){
		*head = temp;
		return;
	}
	
	//look for the last node
	while(it->next)
		it = it->next;
	
	//insert
	it->next = temp;
}

template<class T>
int deleteNodeKey(linkedListNode<T> **head, T o1){
	linkedListNode<T> *i = *head;
	linkedListNode<T> *temp;
	
	//case when the linked list is empty
	if(*head == NULL)
		return 0;
	
	//case when the node to be delted is the head itself
	if(o1 == i->a){
		temp = *head;
		*head = temp->next;
		delete temp;
	}
	
	while(i->next != NULL){
		if(i->next->a == o1){
			temp = i->next;
			i->next = temp->next;
			delete temp;
			return 1;
		}
		i = i->next;
	}
	
	return 0;		//we only reach here if we fail to find the key
}

template<class T>
int deleteNodePos(linkedListNode<T> **head, int pos){
	//case when the linked list is empty
	if(*head == NULL)
		return 0;
	
	linkedListNode<T> *temp;
	//case when we have to delete the head
	if(pos == 0){
		temp = *head;
		*head = temp->next;
		delete temp;
		return 1;
	}
	
	//general case
	int count = 1;
	linkedListNode<T> *it = *head;
	
	while(count != pos && it->next != NULL){		// we come out of this loop with it pointning the the node behind the node number pos
		it = it->next;
		count++;
	}
	
	//check if the linked list ran out 
	if(it->next == NULL)
		return 0;
	else{
		temp = it->next;
		it->next = temp->next;
		delete temp;
		return 1;
	}
}

template<typename T>
void printLinkedList(linkedListNode<T> *head){
	linkedListNode<T> *it = head;
	while(it){
		std::cout<<it->a<<" ";
		it = it->next;
	}
	return;
}

template<class T>
unsigned long int sizeLinkedList(linkedListNode<T> *head){
	unsigned long int c = 0;
	linkedListNode<T> *it = head;
	while(it){
		c++;
		it = it->next;
	}
	return c;
}

#endif
