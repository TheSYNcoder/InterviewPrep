class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        map<int , int> m;
        for ( int x : nums) m[x]++;
       
        sort( nums.begin() , nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for ( int i =0 ; i < n ; i ++ ){
            int j = i +1;
            int k = n -1;
            if ( i > 0 && nums[i] == nums[i-1]) continue;
            
            while( j < k ){
                if ( k < n-1 && nums[k] == nums[k+1]){
                    k--;continue;
                }
                    
                
                if ( nums[i] + nums[j] + nums[k] < 0 )
                    j++;
                else if ( nums[i] + nums[j] + nums[k] > 0 )
                    k--;
                else{
                    vector<int> tmp;
                    tmp.push_back( nums[i]);
                    tmp.push_back( nums[j]);
                    tmp.push_back( nums[k]);
                    ans.push_back(tmp);
                    j++;
                    k--;
                }
                
            }
        }
        return ans;
    }
};
