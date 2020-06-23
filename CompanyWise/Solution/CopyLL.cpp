/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * iter = head ;
        Node * next;
        
        while ( iter ){
            next = iter->next;
            Node * newcopy = new Node(iter->val);
            iter->next = newcopy;
            newcopy->next = next;
            iter = next;
        }
        iter = head;
        while( iter){
            next = iter->next->next;
            if ( iter->random ){
                iter->next->random = iter->random->next;
            }
            iter = next;
        }
        
        Node * pseudo = new Node(0);
        Node * copyiter = pseudo;
        iter = head ;
        while( iter){
            next = iter->next->next;
            copyiter -> next  = iter -> next;
            copyiter = iter->next;
            iter->next = next; // Restoring the original list
            iter = next;   
        }
       
        return pseudo->next;
    }
};
