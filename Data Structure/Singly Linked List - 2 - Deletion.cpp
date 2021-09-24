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

void deleteNodeWithKey( Node** head_ref, int key ) 
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

/*
	Delete a node at the given position
*/
void deleteNodeWithPosition( Node** head_ref, int position ) 
{
	// Check if the linked list is empty
	if( *head_ref == NULL ) 
		return;

	// Store head node
	Node* temp = *head_ref;

	// If head needs to be removed
	if( position == 0 ) {
		// change head
		*head_ref = temp -> next;
		// free old head
		delete temp;
		return;
	}

	// Else find previous node of the node to be deleted
	for( int i = 0; temp != NULL && i < position - 1; i++ ) { 
		temp = temp -> next;
	}

	// If the position is more than the number of nodes
	if( temp != NULL || temp -> next != NULL ) 
		return;

	// Else 'temp -> next' is the node to be deleted
	// Store pointer to the next of node to be deleted
	Node* next_node = temp -> next -> next;

	// Unlink the node from the linked list
	delete temp -> next; // Free memory

	// Unlink the deleted node from the list
	temp -> next = next_node;
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

	deleteNodeWithKey( &linked_list, 40 );
	printList( linked_list );

	deleteNodeWithKey( &linked_list, 60 );
	printList( linked_list );

	/*
		Output:
		Linked List : 60 50 40 30 20 10 
		Linked List : 60 50 30 20 10 
		Linked List : 50 30 20 10 
	*/
	return 0;
}
