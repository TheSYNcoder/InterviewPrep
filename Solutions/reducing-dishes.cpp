class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort( satisfaction.begin() , satisfaction.end() );
        int n = satisfaction.size();
        vector<int> suff( n+1,0);
        for ( int i =  n-1; i >= 0  ; i --){
            suff[i] =  satisfaction[i];
            suff[i] += suff[i+1];
        }
        int ptr = n-1;
        while( satisfaction[ptr] >= 0 && ptr > 0) ptr--;
        int curr =0;
        for ( int i = n-1; i >= ptr ; i--) curr += suff[i]; 
        for ( int i = ptr-1 ; i>= 0 ; i--)
            if ( curr + suff[i] > curr)
                curr = curr + suff[i];
            else
                break;
        return max(0 ,curr);
    }
};
