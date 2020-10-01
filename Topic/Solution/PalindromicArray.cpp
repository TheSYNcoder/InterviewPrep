#include <bits/stdc++.h>
using namespace std;




int arr[102];
int main() {
	int t;
	cin >> t;
	while(t--){
	    int n ;
	    cin >> n;
	    for ( int i =0 ;i < n ; i ++) cin >> arr[i];
	    int st = 0 , et = n-1; int ans=0;
	    while( et - st > 0 ){
	        if ( arr[st] == arr[et]){
	            st++;
	            et--;
	            continue;
	        }
	        if (arr[st] < arr[et]){
	            arr[st+1]+=arr[st];st++;
	            ans++;
	        }
	        else{
	            arr[et-1]+=arr[et]; et--;
	            ans++;
	        }
	    }
	    cout << ans << "\n";
	}
}
