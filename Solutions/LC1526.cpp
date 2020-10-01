class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=target[0];
        int n=target.size();
        for(int i=1;i<n;i++){
            if(target[i]>target[i-1])
                ans+=target[i]-target[i-1];
        }
        return ans;
    }
};