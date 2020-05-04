#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int n = 1e9;

int no( string s){
	int pow  = 1; int ret = 0;
	for ( char c  :s)  {
		ret = ret*10 + (c-'0');
	}
	return ret;
}
vector<int> ans;
void rec( string s){
	if  ( no(s) > n) return ;
	for ( int i = 0  ; i <= 9 ; i++ ){
		if (s.empty() && i == 0 ) continue;
		if (s.empty() || abs(s.back() - '0' - i) == 1 ){
			string t = s;
			t += (char) (i  + '0');
			if ( no(t) <= n)
			ans.push_back(no(t));
			rec(t);
		}
	}
}
int arr[120];
signed main() 
{	
    int t;
    cin >> t;
    for ( int i = 0 ; i < t ; i ++ ) cin >> arr[i];
    string ret="";
    ans.push_back(0);
    rec(ret);
    sort(ans.begin(), ans.end());
    for ( int i = 0 ; i < t; i ++ ){
        for ( int x : ans){
            if ( x > arr[i]) {cout << "\n"; break;}
            cout << x << " ";
        }
    }
    
    return 0;
}
