class Solution {
public:
    
    
    
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair< TreeNode* , int >  > q;
        q.push( { root , 0 } );
        int ans =0;
        
        while( !q.empty()){
            int sz = q.size();
           
            int left = INT_MAX;
            while(sz--){
               
                auto top= q.front(); 
                q.pop();
                if ( left == INT_MAX)
                    left = top.second;
                
                if ( top.first ->left)
                    q.push({ top.first ->left , (top.second - left) * 2 });
                if ( top.first -> right)
                    q.push({ top.first ->right , (top.second - left) * 2 + 1 });
                
                ans = max( ans , top.second - left);
                
            }
            
            
        
        }
        
        return ans +1 ;
    }
