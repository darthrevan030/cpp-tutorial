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
                                                        the original linked list*/ 
    
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

int main(){

    Node *head = nullptr; // initialise head pointer

    insertNewNodeToListEnd(head, 12.5);
    insertNewNodeToListEnd(head, 13);

    cout << "1st Node: " << head -> value << endl;
    cout << "2nd Node: " << head -> next -> value << endl;
}

