#include<bits/stdc++.h>
using namespace std ; 
const long long  mod = 1e9 +  7 ; 
long long dp[1000002] ; 
int main(){
    int n ; 
    cin>>n ; 
    memset(dp,-1,sizeof(dp));
    dp[0] = 1 ; 
    dp[1] = 1 ; 
    for(int  i = 2 ; i <=n ; ++i ){
        long long sum = 0 ; 
        for(int  j = 1 ; j <= 6 ; j++ ){
            if( i - j >= 0){
                sum += dp[i-j] ; 
                if(sum > mod)
                    sum %= mod ;
            }
 
        }
        dp[i] = sum ; 
    }
    cout<<dp[n]; 
}