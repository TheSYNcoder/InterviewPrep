#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* random;

    Node(int data) : data(data), next(NULL), random(NULL) {}
};


Node* clone(Node* head){
    if(head == NULL) return NULL;
    
    Node* travellingPtr = head;

    // Insert clone node of n-th node between original n-th node and (n + 1)-th node 
    while(travellingPtr){
        Node* temp = travellingPtr->next;

        travellingPtr->next = new Node(travellingPtr->data);

        travellingPtr->next->next = temp;

        travellingPtr = temp;
    }

    travellingPtr = head;

    // Clone random pointer of clone nodes
    while(travellingPtr) {
        if(travellingPtr->next)
            travellingPtr->next->random = travellingPtr->random? travellingPtr->random->next: travellingPtr->random;

        travellingPtr = travellingPtr->next? travellingPtr->next->next: travellingPtr->next;
    }

    Node* originalHead = head, *cloneHead = head->next, *finalPtr = head->next;


    // Split it into two list, which will produce additional copy of original List 
    while(originalHead && cloneHead) {
        originalHead->next = (originalHead->next? originalHead->next->next : originalHead->next);

        cloneHead->next = (cloneHead->next? cloneHead->next->next: cloneHead->next);

        originalHead = originalHead->next;
        cloneHead = cloneHead->next;
    }

    return finalPtr;
}
