#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;
 lld splitArray(vector<int>& nums, lld m) {
        lld prefix[nums.size()];
        lld suffix[nums.size()];
        lld len = nums.size();
        if(len == 1){
            return nums[0];
        } 
        prefix[0] = nums[0];
        for(lld i = 1 ; i < len ; i++){
            prefix[i] = prefix[ i - 1] + nums[i];
        }
        suffix[len - 1] = nums[len - 1];
        for(lld i = len - 2 ; i >= 0 ; i--){
            suffix[i] = suffix[i + 1] + nums[i];
        }
        lld dp[len][m + 1];
        memset(dp, 0, sizeof(lld)*len*(m + 1));
        for(lld i = 0 ; i < len ; i++){
            dp[i][1] = prefix[i];
        }
        for(lld i = 2 ; i <= m ; i++){
            for(lld j = 0 ; j < len ; j++){
                dp[j][i] = __INT64_MAX__;
                for(lld k = 1 ; k <= j ; k++){
                    if((j - k + 1) >= (i - 1)){
                        dp[j][i] = min(dp[j][i], max(dp[j - k][i - 1], prefix[j] - prefix[j - k]));
                    }
                }
            }
        }
        return dp[len - 1][m];
    } 
    int main(){
       /* input arr, m*/
        
        vector<int> arr;
        int m;
        cout << splitArray(arr, m);
    }