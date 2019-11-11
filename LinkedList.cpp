#include "LinkedList.h"
#include <iostream>
#include <ctime>
using namespace std;

LinkedList::LinkedList(){
    //initialize head to NULL
    head = NULL;
}

LinkedList::~LinkedList(){
    //reset head to NULL
    head = NULL;
}

void LinkedList::add(string v){
    //adds a new node in the correct position
    ListNode *node = new ListNode(v,NULL);
    if(head == NULL){
        //case if there is an empty list
        head = node;
        return;
    }
    if(head->value.compare(v) >= 0){
        //case if the new node needs to be added to the head
        node->next = head;
        head = node;
        return;
    }
    ListNode *curr = head;
    //determine where the new node should be added
    while(curr->next != NULL){
        if(curr->next->value.compare(v) >= 0){
            //need to add the node
            ListNode *temp = curr->next; //hold the next pointer
            curr->next = node;
            node->next = temp;
            return;
        }
        curr = curr->next;
    }
    //needs to be added to the end
    curr->next = node;
}

void LinkedList::printList(){
    //prints the entire list to the screen
    ListNode *curr = head;
    while(curr != NULL){
        //print the value for each node
        cout << "\t" << curr->value << endl;
        curr = curr->next;
    }
}
