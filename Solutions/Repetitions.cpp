#include<bits/stdc++.h>
using namespace std ;
int main(){
    string s ; 
    cin>>s;
    int  n = s.size() ; 
    int mx  = 1 , cur = 1 ; 
    for(int  i = 1 ; i < n ;++i ){
        if(s[i]==s[i-1])
        {
            cur++ ; 
            if(cur > mx)
                mx = cur ; 
        }
        else{
            cur = 1 ; 
        }
    }
    cout<<mx;
    return 0 ; 
}