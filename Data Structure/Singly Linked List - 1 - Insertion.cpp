#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};


// Given a reference (pointer to pointer)
// to the head of a list and an int,
// inserts a new node on the front of the list.
void push ( Node** head_ref, int new_data ) 
{
	/* 1. allocate node */
	Node* new_node = new Node();

	/* 2. put in the data */
	new_node -> data = new_data;

	/* 3. Make next of new node as head */
	new_node -> next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}

// Given a node prev_node, insert a
// new node after the given 
// prev_node
void insertAfterNode ( Node* prev_node, int new_data ) 
{
	/* 1. check if the previous node is null */
	if( prev_node == NULL ) {
		std::cout << "the given previous node cannot be null" << endl;
		return;
	}

	/* 2. allocate new node */
	Node* new_node = new Node();

	// 3. put in the data
	new_node -> data = new_data;

	// 4. Make next of new_node as next of prev_node
	new_node -> next = prev_node -> next;

	// 5. move the next of prev_node as new_node
	prev_node -> next = new_node;
}

void insertAfterFirstFoundValue( Node** head_ref, int old_data, int new_data ) 
{
	if( *head_ref == NULL ) {
		std::cout << "the list is empty" << endl;
		return;
	}
	Node* tmp_node = *head_ref;

	while( tmp_node -> next != NULL ) {
		if( tmp_node -> data == old_data ) {
			break;
		}
		tmp_node = tmp_node -> next;
	}

	if( tmp_node -> data == old_data ) {
		Node* new_node = new Node();
		new_node -> data = new_data;
		new_node -> next = tmp_node -> next;
		tmp_node -> next = new_node;
		return;
	}

	std::cout << old_data << " not found" << endl;
	return;
}

void insertAfterLastFoundValue( Node** head_ref, int old_data, int new_data ) 
{
	// 1. check if the list is empty
	if( *head_ref == NULL ) {
		std::cout << "the list is empty" << endl;
		return;
	}

	Node* tmp_node = *head_ref;
	Node* expected_node = new Node();

	// 2. search for old_data in the list
	while( tmp_node -> next != NULL ) {
		if( tmp_node -> data == old_data ) {
			expected_node = tmp_node;
		}
		tmp_node = tmp_node -> next;
	}

	// 3. if the node with the given value is found, 
	//    then insert the new node after the found node

	// 3(a). call "insertAfterNode()" function:
	insertAfterNode( expected_node, new_data );
	return;

	// 3(b). or do it manually
	if( expected_node != NULL ) {
		Node* new_node = new Node();
		new_node -> data = new_data;
		new_node -> next = expected_node -> next;
		expected_node -> next = new_node;
		return;
	}

	std::cout << old_data << " not found" << endl;
	return;
}
// Given a reference (pointer to pointer) to the head 
// of a list and an int, appends a new node at the end
void append ( Node** head_ref, int new_data ) 
{
	// 1. allocate node
	Node* new_node = new Node();

	// used in step 5
	Node *last = *head_ref;

	// 2. Put in the data
	new_node -> data = new_data;

	// 3. this new_node is going to be the last node,
	//    so make next of it as null
	new_node -> next = NULL;

	// 4. if the linked list is empty,
	//    then make the new node as head
	if( *head_ref == NULL ) {
		*head_ref = new_node;
		return;
	}

	// 5. Else traverse till the last node
	while( last -> next != NULL ) 
		last = last -> next;

	// 6. change the next of last node
	last -> next = new_node;
}

void printList ( Node* n )
{
	std::cout << "linked list : ";
	while( n != NULL ) {
		std::cout << n -> data << " ";
		n = n -> next;
	}
	std::cout << endl;
}

int main() 
{
	Node* linked_list = NULL;

	append( &linked_list, 10 );
	append( &linked_list, 20 );
	append( &linked_list, 30 );
	append( &linked_list, 40 );
	append( &linked_list, 50 );
	printList( linked_list );


	push( &linked_list, 7 );
	printList( linked_list );

	push( &linked_list, 1 );
	printList( linked_list );


	insertAfterNode( ((linked_list -> next) -> next) -> next, 5 );
	printList( linked_list );


	insertAfterFirstFoundValue( &linked_list, 5, 5555 );
	printList( linked_list );


	insertAfterLastFoundValue( &linked_list, 5555, 6666 );
	printList( linked_list );

	printList( linked_list );
	/*
		Output:
		linked list : 10 20 30 40 50 
		linked list : 7 10 20 30 40 50 
		linked list : 1 7 10 20 30 40 50 
		linked list : 1 7 10 20 5 30 40 50 
		linked list : 1 7 10 20 5 5555 30 40 50 
		linked list : 1 7 10 20 5 5555 6666 30 40 50 
		linked list : 1 7 10 20 5 5555 6666 30 40 50  
	*/
	
}
