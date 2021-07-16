class Solution {
public:
    int minFlips(string s) {
        int originalLength = s.size();
        string formed = s + s;
        int minScore = 1e9;
        int expected = 0;
        int score1 = 0 , score2 = 0 ;
        for ( int i= 0 ; i < formed.size() ; i++ ){
            
            if ( formed[i] - '0' != expected ) score1++;
            if ( formed[i] - '0' == expected ) score2++;
            if ( i >= originalLength ){
                int expback = expected ^ ( originalLength & 1);
                if ( formed[i] - '0' != expback ) score1--;
                if ( formed[i] - '0' == expback ) score2--;
            }
            if ( i + 1 >= originalLength ){
                minScore = min({ minScore , score1, score2 } );                
            }            
            expected ^= 1;
            
        }
        return minScore;
    }
};
