    bool isPerfectSquare(int num) {
        
        double lo=0,hi=num;
        while(lo<=hi){
            double mid=(int)(lo+(hi-lo)/2);
            // cout<<mid<<endl;
            try{
            if(mid*mid==num){
                return true;
            }
            if(mid*mid>num)
                hi=mid-1;
            else lo=mid+1;
            }
            catch(...){
                hi=mid-1;
            }
        }
        return false;
    }