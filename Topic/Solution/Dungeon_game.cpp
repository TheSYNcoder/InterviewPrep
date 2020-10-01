class Solution {
    bool checkGame(vector<vector<int>> dungeon,int health){
        int r=dungeon.size();
        int c=dungeon[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int prev=-1;
                if(i==0&& j==0){ dungeon[0][0]+=health;continue;}
                else if(i==0) prev=dungeon[0][j-1];
                else if(j==0) prev=dungeon[i-1][0];
                else{
                    prev=max(dungeon[i-1][j],dungeon[i][j-1]);
                }
                
                if(prev<=0) dungeon[i][j]=-1;
                else dungeon[i][j]+=prev;
                
            }
        }
        return dungeon[r-1][c-1]>0;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      int lo=1,hi=INT_MAX-1;
        while(hi>lo){
            int mid=(hi+lo)/2;
            cout<<mid<<" ";
           if(checkGame(dungeon,mid)){
               hi=mid;
           } 
            else{
                lo=mid+1;
            }
        }
        return hi;
    }
};