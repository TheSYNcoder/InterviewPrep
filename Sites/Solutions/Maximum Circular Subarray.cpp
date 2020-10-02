class Solution {
public:
    int kadane( vector<int> a ){
        int ans=INT_MIN;
        int sum = 0 ;
        for ( int x : a ) {
            sum += x;
            ans = max( ans, sum );
            sum = max( sum ,0 );
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        int ans1 = kadane(A);
        int sum = 0;
        for ( int &x : A){
          sum += x;
          x =-x;
        } 
        int ans2= kadane(A); 
        ans2 = ans2 + sum == 0 ? INT_MIN : sum  + ans2;
        return max( ans1 , ans2);
    }
};
