#include<bits/stdc++.h>

using namespace std;

int solve(string& s1, string& s2, int n, int m){
    
    int DP[n + 1][m + 1];
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0) 
                DP[i][j] = j;
            else if(j == 0) 
                DP[i][j] = i;
            else if(s1[i - 1] == s2[j - 1]) 
                DP[i][j] = DP[i - 1][j - 1];
            else 
                DP[i][j] = 1 + min(DP[i - 1][j - 1], min(DP[i][j - 1], DP[i - 1][j]));
        }
    }
    
    return DP[n][m];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while(t--){
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        cout << solve(s1, s2, n, m) << "\n";
    }
    return 0;
}
