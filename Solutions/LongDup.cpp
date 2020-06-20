#define ll long long int
class Solution {
public:
    
    const ll mod = 1e9 + 9;
    const ll prime = 31;
    const ll maxn = 1e5 + 5;
    ll p_pow[100005];
    
    ll exp( ll a , ll p ){
        if ( p == 1) return a;
        if ( p% 2) return (a%mod * exp( (a%mod * a%mod)%mod , p /2 ) %mod )%mod;
        else return exp( (a%mod * a%mod)%mod , p /2 ) %mod;
    }
    
    ll mul( ll a , ll b){
        return ( a%mod * b%mod) %mod;
    }
    
    void init( ll  n ){
        p_pow[0]=1;
        for ( ll i = 1; i <= n ; i++) p_pow[i] = (p_pow[i-1] * 26)%mod;
    }
    
    
    string check(ll k , string s) {
        if ( k == 0) return "";
        unordered_map<ll, vector<ll> > m ;
        ll hash =0;
        ll n  = s.size();
        
        for ( int i = 0 ; i < k ; i ++){
            hash = (hash * 26 + s[i])%mod;
        }
        m[hash] = {0};
        ll curr = hash;
        for ( ll i = k ; i < n ; i++){
            curr = (curr + mod - mul( 1LL*s[i-k] , p_pow[k-1]  )%mod )%mod;
            curr = (curr * 26 + s[i])%mod;
            if ( m.find(curr) == m.end()){
                m[curr] = { i - k +1LL};
            }
            else{
                for ( ll x : m[curr]){
                    string ff = s.substr( x , k);
                    if ( ff == s.substr( i- k +1 , k)) return ff;
                }
                    m[curr].push_back( i - k+1);
                
            }
        }
        return "";
        
        
    }
    
    
    string longestDupSubstring(string s) {
        ll h = s.size();
        init(h);
        ll l  = 0;
        string ans;
        int len =0;
        while( h - l > 0 ){
            ll m = ( h + l) /2;
            string x = check( m , s);
            
            if ( ans.size() < x.size()) {     
                ans =x;
                l = m+1;
            }
            else{
                h = m;
            }
        }
        return ans;
    }
};
