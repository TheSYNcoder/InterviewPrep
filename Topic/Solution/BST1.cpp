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
    int maxLevelSum(TreeNode* root) {
        int level =0;
        int mx = 0 ; 
        int ans = 0 ;
        
        queue<TreeNode *> q;
        q.push(root);
        while( !q.empty()){
            level++;
            int sz = q.size();
            int curr =0 ; 
            
            while( sz--){
                TreeNode * top = q.front();
                q.pop();
                curr += top -> val;
                if ( top->left)
                q.push( top->left);
                if ( top->right)
                q.push( top->right);
            }
            if ( mx < curr){
                mx = curr;
                ans = level;
            }
        }
        return ans;
        
    }
};
