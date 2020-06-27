class Solution {
public:
    // https://brilliant.org/wiki/egg-dropping/
    // Last Part
    int superEggDrop(int egg, int floor) {
        // DP represents total number of floor can be covered
        // with x moves and y eggs left, by DP[x][y]
        // DP[c][y] = 1 + DP[x - 1][y - 1] + DP[x - 1][y]
        int DP[floor + 1][egg + 1]; // Max number of moves possible is equals to number of floors
        
        for(int i = 0; i <= floor; i++)
            for(int j = 0; j <= egg; j++)
                DP[i][j] = 0;
        
        int ans = 0;
        while(DP[ans][egg] < floor){
            ans++;
            for(int i = 1; i <= egg; i++)
                DP[ans][i] = 1 + DP[ans - 1][i - 1] + DP[ans - 1][i];
        }
        return ans;
    }
};
