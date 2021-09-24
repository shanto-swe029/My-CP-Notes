#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void push( Node** head_ref, int new_data ) 
{
	Node* new_node = new Node();
	new_node -> data = new_data;
	new_node -> next = (*head_ref);
	(*head_ref) = new_node;
	return;
}

/*	                Iterative Method
	----------------------------------------------------
	To delete a node from the linked list,
	we need to do the following steps:
	1. Find the previous node of the node to be deleted
	2. Change the next of previous node
	3. Free memory of the node to be deleted
*/

void deleteNode( Node** head_ref, int key ) 
{
	// store the head node
	Node* temp = *head_ref;
	Node* prev = NULL;

	// If the head node itself holds the key to be deleted
	if( temp != NULL && temp -> data == key ) {
		*head_ref = temp -> next;
		delete temp;
		return;
	}

	// Search for the key to be deleted,
	// keep track of the previous node as 
	// we need to change 'prev -> next'.
	while( temp != NULL && temp -> data != key ) {
		prev = temp;
		temp = temp -> next;
	}

	// If the key was not present in the list
	if( temp == NULL )
		return;

	// unlink the node from the linked list
	prev -> next = temp -> next;

	// free memory
	delete temp;
}

void printList ( Node* node ) 
{
	std::cout << "Linked List : ";
	while( node != NULL )
	{
		std::cout << node -> data << " ";
		node = node -> next;
	}
	std::cout << endl;
}

int main()
{
	Node* linked_list = NULL;

	// add elements in the linked list
	push( &linked_list, 10 );
	push( &linked_list, 20 );
	push( &linked_list, 30 );
	push( &linked_list, 40 );
	push( &linked_list, 50 );
	push( &linked_list, 60 );
	
	printList( linked_list );

	deleteNode( &linked_list, 40 );
	printList( linked_list );

	deleteNode( &linked_list, 60 );
	printList( linked_list );

	/*
		Output:
		Linked List : 60 50 40 30 20 10 
		Linked List : 60 50 30 20 10 
		Linked List : 50 30 20 10 
	*/
	return 0;
}
