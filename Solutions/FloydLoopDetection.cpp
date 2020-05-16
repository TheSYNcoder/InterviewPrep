/**
*
*
* Proof
* Let size of cycle =l , size before cycle = b , distance travelled by small = ( b +x ) , fast = f
* or  2 * ( b +x ) = f where f = b + x + n* l for some n , n is an integer
* or b +x = n * l 
* or b = n*l - x
* 
*
* for n =1 , when moving the slow and fast pointer at same speed one from beginning and another from 
* their point of intersection we can reach b, which is the start of the loop.
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if ( !head) return NULL;
        ListNode * slow =head;
        ListNode * fast =head;
        ListNode* ans=NULL;
        while( fast->next && fast->next->next ){
            slow = slow->next;
            fast = fast->next->next;
            if ( slow == fast){
                ans =slow;
                break;
            }
        }
        slow = head;
        if ( ans){
            while( true){
                if (slow == ans) break;
                slow = slow->next;
                ans=ans->next;
            }
        }
        return ans;
    }
};
