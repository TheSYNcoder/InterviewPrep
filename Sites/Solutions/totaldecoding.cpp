#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int stooi(string str){
    int val  = 0;
    for(int i = str.length() - 1 ; i>=0 ; i--){
        val = val + (str[i] - '0')*pow(10, str.length() - 1 - i);
    }
    return val;
}
int main() {
    //cout << stooi("1234");
	int testcases;
	cin >> testcases;
	while(testcases-- != 0){
	    int n;
	    cin >> n;
	    string str;
	    cin >> str;
	    int dp[n + 1];
	    dp[0] = 1;
	    dp[1] = 1;
        if(str[0] == '0'){
            cout << '0' << '\n';
            continue;
        }
       
	    dp[2] = (stooi(str.substr(0, 2)) <= 26)?((str[1] == '0') ? 1 : 2):((str[1] == '0')?0:1);
	    if(dp[2] == 0){
            cout << 0 << '\n';
            continue;
        }
	    for(int i = 3 ; i <= n ; i++){
	       
            if(str[i - 1] == '0'){
                if(stooi(str.substr(i - 2, 2)) <= 26 && stooi(str.substr(i - 2, 2)) >= 1){
                    dp[i] = dp[i - 2];
                    continue;
                }
                else{
                    dp[n] = 0;
                    break;
                }
                
            }
             if(str[i - 2] == '0'){
	            dp[i] = dp[i - 1];
	            continue;
	        }
	        dp[i] = dp[i - 1];
	        if(stooi(str.substr(i - 2, 2)) <= 26){
	            dp[i] += dp[i - 2];
	        }
	    }
	    cout << dp[n] << '\n';
	}
	return 0;
}