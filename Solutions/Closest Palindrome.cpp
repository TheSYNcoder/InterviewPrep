#include <bits/stdc++.h>
using namespace std; 
#define int long long int
#define max(x, y) ((x) > (y) ? (x) :(y))
#define pii pair< int , int> 
#define vi vector<int>
#define fore( i ,st) for ( int i= 0 ; i < (int)(st) ; i ++)
#define REP( i , st , en ) for ( int i =st; i < (int)en; i++)
#define REPD( i , en , st ) for ( int i =en; i >= (int)st; i--)
#define SZ(a) (int)a.size()
#define all(v) v.begin() , v.end()
#define pb push_back
#define F first
#define S second
#define bitch_i_m_on_fiyaah_yeahhhh ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// const int mod = 998244353;
const int mod = 1e9+7;
ostream& operator << ( ostream&  o, vector<int> s){for ( int i = 0;  i < (int)s.size() ; i++)o << s[i] << " ";o << "\n";return o;}
void  add( int &a, int b){a = a + b;if ( a< 0 ) a += mod; if ( a> mod ) a-= mod;}
void sub( int &a, int b){a = a - b;if ( a < 0) a += mod;}
int mul( int a , int b){return ((a %mod) * (b %mod) ) %mod;}
int exp( int a , int pow){ return (pow == 0 ? 1 : ( pow & 1  ? mul ( a ,exp( mul(a, a) , pow /2) ) : exp(mul(a ,a) , pow/2)));}
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
// const int inf = 1e18;
 
const int maxn = 2e5 + 5;

string num( string x , int a){
	int res = 0;
	for ( int i = 0 ; i < x.length() ; i ++ )
		res = res * 10 + x[i] - '0';  
	return to_string(res+a );
}

string rev( string t){
	reverse( all(t));
	return t;
}
int no( string a){
	int res =0;
	for ( int i = 0; i < a.size();  i++ ) res = res * 10 + a[i]-'0';
	return res;
}

int diff( string a , string b){
	int na = no(a); int nb = no(b);
	return abs(na - nb);
}

string palin( string s , int a){
	int n = s.length();
	string left = s.substr( 0 , n /2);
	string middle = s.substr( n /2 , n&1);
	string right = s.substr( n - n /2 );
	string next= num( s.substr(0 , left.length() + middle.length()) , a);
	return (  next + rev(next.substr(0 ,left.length())));	
}

void solve(int test ) 
{	
	string s;
	cin >> s;
	string ans;
	int mn = INT_MAX;
	for ( int i = -10 ; i  <= 10 ; i ++ ) {
		string x = palin( s , i);
		if ( mn > diff( x , s)){
			mn = diff( x , s);
			ans = x;
		}
	}
	cout << ans << "\n";
}
signed main(){
	// bitch_i_m_on_fiyaah_yeahhhh
	int t =1; 
	cin >> t;
	for ( int i = 0 ; i < t; i++)
	solve(i+1);
}
