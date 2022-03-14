#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* next;
};

node *root = NULL;

void printList() {
    if( root == NULL ) {
        std::cout << "The List Is Empty!" << endl;
        return;
    }
    
    std::cout << "Your Linked List: ";
    node *current_node = root;
    while( current_node != NULL ) {
        std::cout << current_node->val << " ";
        current_node = current_node->next;
    }
    std::cout << endl;
    return;
}

void append( int val ) 
{
    if( root == NULL ) {
        root = new node();
        root->val = val;
        root->next = NULL;
        return;
    }
    
    node *current_node = root;
    
    while( current_node->next != NULL ) {
        current_node = current_node->next;
    }
    node *newNode = new node();
    newNode->val = val;
    newNode->next = NULL;
    current_node->next = newNode;
}

void deleteByValue( int val ) {
    if( root == NULL ) {
        std::cout << "The List Is Empty!" << endl;
        return;
    }
    
    node *current_node = root;
    node *previousNode = NULL;
    bool found = false;
    while( current_node != NULL ) {
        if( current_node->val == val ) {
            found = true;
            break;
        }
        previousNode = current_node;
        current_node = current_node->next;
    }
    if( found ) {
        previousNode->next = current_node->next;
        std::cout << "Successfully Deleted " << val << endl;
        printList();
        return;
    }
    std::cout << "Node not found!" << endl;
}



int main()
{
    append(10);printList();
    append(20);printList();
    append(30);printList();
    append(40);printList();
    append(50);printList();
    
    deleteByValue(40);

    return 0;
}
