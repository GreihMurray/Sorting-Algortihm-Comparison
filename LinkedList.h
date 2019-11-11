#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <string>
using namespace std;

class LinkedList{
    public:
        struct ListNode{
            string value;
            ListNode *next;
            ListNode(string v, ListNode *n){
                value = v;
                next = n;
            }
        };

        ListNode *head;

        LinkedList();
        ~LinkedList();
        void add(string v);
        void printList();
};
#endif // LINKEDLIST_H_INCLUDED
