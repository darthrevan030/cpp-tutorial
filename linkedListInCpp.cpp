#include <iostream>
using namespace std;

/* 
Common Pointer Bugs:
    - Attempting to dereference a pointer via *p or p-> when p == NULL or p == nullptr
    - Attempting to dereference a pointer via *p or p-> when p is not properly initialised

What these bugs result in: --> NOT SYNTAX ERROR
    - Bus Error
    - Segmentation Fault
    - Address protection violation
*/

struct Node{
    double value;
    Node *next;
};

void insertNewNodeToListEnd(Node *&head, double newValue){ /*passes references to pointer instead of the pointer itself. 
                                                        Ensures that any modifications to the head pointer is reflected in 
                                                        the original linked list. If this is not done, then the pointer in the 
                                                        linked list cannot be modified, and therefore the new node will not be 
                                                        linked*/ 
    
    // Creating new Node
    Node *newNode = new Node; // Step 1: allocate memory for new node
    newNode -> value = newValue; // Step 2: initialise contents of the new node
    newNode -> next = nullptr; // Step 3: set pointer field to nullptr

    // Insert the new Node
    if (head == nullptr){ // check if list is empty
        head = newNode; // insert the new node as the head
    } else { // if list is not empty
        Node *temp = head; // initialise temp pointer to iterate through list
        while (temp -> next != nullptr){ // iterate through list while not at the last node
            temp = temp -> next; 
        }
        temp -> next = newNode; // point the pointer of the current last node to the new node
    }

}

/*
- If list uses dynamic memory, then delete node from memory
- Requires 2 pointers
    - One to locate the node to be deleted
    - One to point to the node before the node to be deleted
*/
void deleteNode(Node *&head, double number){
    Node *nodePtr, *prevNodePtr; // initialise the two pointers 

    if (head == nullptr){ // check if the list is empty
        return; // do nothing (eat 5 star) if the list is empty
    }

    if (fabs(head -> value - number)< 1e-9){ // check if the first node is the one to be deleted
        nodePtr = head;
        head = head -> next; 
        delete nodePtr;
        nodePtr = nullptr;
    } else {
        nodePtr = head; // initialise the node pointer to the list head
        
        // skip nodes whose value member is not number
        while (nodePtr != nullptr && fabs(nodePtr -> value - number) > 1e-9){
            prevNodePtr = nodePtr;
            nodePtr = nodePtr -> next;
        }

        // link the previous node to the node after node pointer then delete node pointer
        if (nodePtr != nullptr){
            prevNodePtr -> next = nodePtr -> next;
            delete nodePtr;
            nodePtr = nullptr;
        }
    }
}

int main(){

    Node *head = nullptr; // initialise head pointer

    insertNewNodeToListEnd(head, 12.5);
    insertNewNodeToListEnd(head, 13);

    cout << "1st Node: " << head -> value << endl;
    cout << "2nd Node: " << head -> next -> value << endl;

    deleteNode(head, 12.5);
    
    cout << "1st Node: " << head -> value << endl;
    cout << "2nd Node: " << head -> next -> value << endl;
}

