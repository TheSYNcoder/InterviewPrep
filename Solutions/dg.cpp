class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if ( dungeon.empty()) return  0 ; 
        int n = dungeon[0].size();
        vector<int> need( n, (1 << 30)); need[n-1] = 1;
        for ( int i = dungeon.size() -1 ; i >= 0  ; i--){
            need[n-1] = max( 1 , need[n-1] - dungeon[i][n-1] );
            for ( int j = n -2; j >= 0 ; j--){
                need[j] = max( 1 , min(need[j] ,need[j+1]) - dungeon[i][j]);
            }
        }
        return need[0];
        
    } 
};
