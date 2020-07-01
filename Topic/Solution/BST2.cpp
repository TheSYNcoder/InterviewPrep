/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* middle( ListNode* head){
        ListNode* slow=head;
        ListNode* fast =head;
        ListNode* prev= NULL;
        while( fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is the mid
        // when only head , prev is NULL
        if ( prev)
            prev->next=NULL;
        return slow;
    }
        
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if (!head) return NULL;
        // find middle 
        ListNode* mid = middle( head);
        TreeNode * node = new TreeNode( mid->val);
        
        if ( head == mid) return node;
        node->left = sortedListToBST( head);
        node->right = sortedListToBST(mid->next);
        return node;
        
    }
};
