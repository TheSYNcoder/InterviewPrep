#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define int long long int
signed main() {
	int t;
	cin >> t;
	while( t--){
	    int n ,m;
	    cin >> n >> m ; 
	    vector<int> a(n);
	    vector<int> b(m);
	    for ( int i = 0;  i < n ; i++ )cin >> a[i];
	    for ( int i = 0 ; i < m ; i++) cin >> b[i];
	    int dp[1001][1001]={{0}};
	    for ( int i = 0 ; i < n ; i++){
	        for ( int j = 0 ; j <=i && j < m ; j++){
	            dp[i+1][j+1] = max( dp[i+1][j+1] , dp[i][j] + a[i] * b[j]);
	            dp[i+1][j+1] = max( dp[i+1][j+1] , dp[i][j+1]);
	        }
	    }
	    cout << dp[n][m] << "\n";
	    
	}
	
}
