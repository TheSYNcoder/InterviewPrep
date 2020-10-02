class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        set<vector<int>> set_of_vector;
        
        for(int m = 0; m<n-1; m++){
            int y = nums[m];
            for(int i= m+1;i<n-1;i++)
        {
            int j = i + 1;
            int k = n - 1;
            long x = nums[i];
            while(j < k)
            {
                if(x + nums[j] + nums[k] + y == target)
                {
                    vector<int> data(4);
                    data[0] = nums[m];
                    data[1] = nums[i];
                    data[2] = nums[j];
                    data[3] = nums[k];
                    
                    set_of_vector.insert(data);

                    j++;
                    k--;
                }
                else if(x + nums[j] + nums[k] + y > target)
                    k--;
                else 
                    j++;
            }
        }    
        }
        
        for(auto it = set_of_vector.begin(); it!=set_of_vector.end();it++)
        {
            ans.push_back(*it);
        }

        return ans;
    }
};
