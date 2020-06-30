class Solution {
public:
    
    int dsu[2002];
    int rnk[2002];
    int root( int x){ return dsu[x] = ( x == dsu[x] ? x : root(dsu[x]));}
    void merge( int x, int y){
        int xr = root(x);
        int yr = root(y);
        if ( xr == yr) return ;
        if ( rnk[xr] < rnk[yr]) swap(xr ,yr);
        rnk[xr]++;
        dsu[yr] =xr;
    }
    int conn( string x , string y){
        int diff =0 ; 
        assert( x.size() == y.size());
        for ( int i = 0 ;i < x.size() ; i ++ ){
            if (x[i] != y[i]) diff++;
        }
        return diff <=2;
    }
    int numSimilarGroups(vector<string>& A) {
        iota( dsu , dsu + 2002 , 0 );
        int n = A.size();
        int w = A[0].size();
        
        if ( n < w* w ){
        
        //iterate over the strings
            for ( int i = 0 ; i < A.size() ; i++ ) { 
                for ( int j = i +1 ; j  <A.size() ; j++ ){ 
                    if ( conn( A[i] , A[j])){
                        merge( i , j );
                    }
                }
            }
        }
        else{
            // n * w^3
            map<string , int > dic;
            int c =0;
            for ( string x : A){ dic[x] = c; c++; }
            // map< string , vector<string> > m;
            for ( int i = 0; i < A.size() ; i++ ){
                for ( int l = 0 ; l < w; l++){
                    for ( int r = l +1; r < w; r ++ ){
                        string tmp = A[i];
                        char c = tmp[l];
                        tmp[l] =tmp[r];
                        tmp[r] =c;
                        if ( dic.count(tmp) && conn( tmp , A[i]))
                            merge( dic[tmp] ,  i);
                    }
                }
            }
            
        }
        set<int> s;
        for ( int i = 0 ; i < A.size();  i++ ) s.insert(root(i));
        return s.size();
    }
};
