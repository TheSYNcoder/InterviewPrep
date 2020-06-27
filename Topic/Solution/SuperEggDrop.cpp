class Solution {
public:
    // https://brilliant.org/wiki/egg-dropping/
    // Last Part
    int superEggDrop(int egg, int floor) {
        // DP represents total number of floor can be covered
        // with x moves and y eggs left, by DP[x][y]
        // DP[c][y] = 1 + DP[x - 1][y - 1] + DP[x - 1][y]
        int DP[floor + 1][egg + 1]; // Max moves possible is equals to number of floor
        
        for(int i = 0; i <= egg; i++) DP[0][i] = 0;
        for(int j = 0; j <= floor; j++) DP[j][0] = 0;
        
        int ans = 0;
        while(DP[ans][egg] < floor){
            ans++;
            for(int i = 1; i <= egg; i++)
                DP[ans][i] = 1 + DP[ans - 1][i - 1] + DP[ans - 1][i];
        }
        return ans;
    }
};
