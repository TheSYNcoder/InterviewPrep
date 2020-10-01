class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> ans;
        int count=0, i;
        for(int j=0; j<= num; j++){
            i = j;
            while(i>0){
                if(i%2 == 1) count++;
                i = i/2;
            }
            ans.push_back(count);
            count=0;
        }
        
        return ans;
    }
};
