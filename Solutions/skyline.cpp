class Solution {
public:
    // Solution hint : https://briangordon.github.io/2014/08/the-skyline-problem.html
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<vector<int>> cp;        
        for ( auto x : buildings ){
            cp.insert({ x[0] , x[1],  x[2], 1});
            cp.insert({ x[1] , x[0] , x[2] ,0});            
        }
        set< vector<int> > heap;
        vector<vector<int>> ans;
        for ( auto x : cp){
                    
            if ( x[3]) {
                heap.insert({ x[2], x[0] , x[1]});
            }
            else{
                heap.erase(heap.find({x[2] , x[1] , x[0]}));
            } 
            if ( !ans.empty() && ans.back()[0] == x[0]){
                    ans.pop_back();
            }
            if ( heap.empty()){
                ans.push_back({x[0] ,0 });    
            }
            else
            {   
                if ( ans.empty() || ans.back()[1] !=(*heap.rbegin())[0])
                    ans.push_back({x[0] , (*heap.rbegin())[0]});
            }
        }
        return ans;
    }
};
