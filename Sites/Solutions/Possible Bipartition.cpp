
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph( N );
        for ( auto  x : dislikes ){
            x[0]--;x[1]--;
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        queue< int > q;
        vector<int> color(N ,-1);
        for ( int v = 0; v < N ; v++){
            if ( color[v] == -1){
                q.push(v);
                color[v]=1;
                while( !q.empty()){
                    int top = q.front();
                    q.pop();
                    for ( int x : graph[top]){
                        if ( color[x] == -1){
                            color[x] = 3 - color[top];
                            q.push(x);
                        }
                        else if ( color[x] == color[top]) return false;
                    }
                }
            }
        }
        return true;
    }
};



/*
DFS
*/


class Solution {
public:

    int  dfs( vector<vector<int>> graph , vector<int> &color , int src ,int col =1){
        for ( int  x : graph[src]){
            if  (color[x] == -1){
                color[x] = 3 -col;
                if (!dfs(graph , color , x , 3 -col ,src)) return 0;
            }
            else if ( color[x] == col) return 0;
        }
        return 1;
    }

    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph( N );
        for ( auto  x : dislikes ){
            x[0]--;x[1]--;
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        bool ok = true;
        vector<int> color(N ,-1);
        for ( int v = 0; v < N ; v++){
            if ( color[v] == -1){
                color[v] =1;
                ok&=dfs(graph ,color , v);
             }
        }
        return ok;
    }
};
