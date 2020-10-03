#include<bits/stdc++.h>
using namespace std ; 
int main(){
    int n ; 
    cin>> n ;
    vector<int> dp(n+1) ; 
    int x ;
    for(int i = 1 ; i < n ; ++i){
        cin>>x ; 
        dp[x]++ ; 
    }
    for(int i = 1 ; i <=n ;i++){
        if(dp[i]==0)
        {
            cout<<i;
            break;
        }
    }
 
    return 0 ;
}