#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int INF = 2e6 + 69 ;  
signed main(){
    int n  , x ; 
    cin>>n>>x; 
    vector<int> c(n), dp(x + 2, INF ) ; 
    for(int i = 0 ; i < n ; ++i)
        cin>>c[i] ; 
    dp[0] = 0 ; 
    for(int i = 1 ; i <= x ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            if( i - c[j] >= 0 )
                dp[i] = min(dp[i] , 1 + dp[i - c[j]]) ; 
        }
    }
    if(dp[x]==INF)
        cout<<-1;
    else
     cout<<dp[x];
}