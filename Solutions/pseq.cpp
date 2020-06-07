class Solution {
public:
    string getPermutation(int n, int k) {
       
        int fact[11]={0};
        fact[0]=1;
        for ( int i =1; i <= 10; i++) fact[i] = i * fact[i-1];
        string s;
        for ( int i= 0; i < n ; i++) s.push_back( (char)( i +1+ '0'));
        if ( k <= 1 ) return s;
        k--;
        for ( int i =0 ; i < n -1; i++){
            int f = fact[n-1-i];
            
            int index= k / f;
            // right shift 
            char temp = s[ i + index];
            for ( int j = i + index ; j > i ; j--) 
                s[j] = s[j-1];
            s[i] = temp;
            
            // change k
            k = k - f * index;
        }
        return s;
    
        
    }
};
