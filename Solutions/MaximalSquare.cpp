int maximalSquare(vector<vector<char>>& matrix) {
        if ( matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int> > dp( n+1 , vector<int>(m+1 ,0));
        for ( int i = 0 ; i < n ; i++){
            for ( int j = 0 ; j < m ; j++){
                  if (matrix[i][j] == '1'){
                      dp[i+1][j+1] = 1 + min( {dp[i][j] , dp[i+1][j] , dp[i][j+1]});
                  }
                else dp[i+1][j+1] = 0;  
                
            }
        }
        int ans =0;
        for ( int i =0 ; i <=n ; i++){
            for ( int j = 0; j <= m ; j ++) ans = max( ans , dp[i][j]);
            
        }
        return ans*ans;
        
        
    }
