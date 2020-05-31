class Solution {
    int get(vector<vector<int>>& t,int r,int c, vector<vector<int>>& dp){
        if(r==0 && c==0)
            return dp[r][c]=t[0][0];
        if(c<0 || c>r)
            return INT_MAX/2;
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        vector<int> v=t[r];
        // int ans=INT_MAX/2;
        for(int i=0;i<v.size();i++){
            int ans1=get(t,r-1,i,dp);
            int ans2=get(t,r-1,i-1,dp);
            
            // ans=t[r][i]+min(ans,max(ans1,ans2));
            dp[r][i]=t[r][i]+min(ans1,ans2);
        }
        return dp[r][c];
    }
public:
    int minimumTotal(vector<vector<int>>& traingle) {
        int r=traingle.size();
        int c=traingle[r-1].size();
        vector<vector<int>> dp(r,vector<int> (c,-1));
        int ans=get(traingle,r-1,0,dp);
        // for(auto i: dp){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return *min_element(dp[r-1].begin(),dp[r-1].end());
    }
};