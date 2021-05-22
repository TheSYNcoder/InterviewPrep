long countTriplets(vector<long> arr, long r) {
    
    map< long, long > m2; 
    map< long , long > m3;

    long cnt = 0;

    // triplet a ,b ,c
    for ( long x : arr ){
        // incoming x is the b of the current triplet
        if ( m3.count(x)) // completed triplets
            cnt += m3[x];
        if ( m2.count(x)) // there are occurences of x/r before
            m3[x * r] += m2[x]; // computing c for a triplet
        m2[x * r ]++; // computing a for a future triplet 
        
    }   

    return cnt;

     

}
