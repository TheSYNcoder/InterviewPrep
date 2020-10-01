class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> res;
        int c=0, i;
        for(int j=0; j<= num; j++){
            i = j;
            while(i>0){
                if(i%2 == 1) c++;
                i = i/2;
            }
            res.push_back(c);
            c=0;
        }
        
        return res;
    }
};
