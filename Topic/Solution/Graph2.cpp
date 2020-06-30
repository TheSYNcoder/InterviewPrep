class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         
        queue<int> q;
        int n = graph.size();
        int in[10001];
        fill( in , in + n+1,0);
        
        vector< vector<int> > edges(n);
        for ( int i = 0 ; i < n ; i++){
            for ( int x : graph[i]) {
                edges[x].push_back(i);
                in[i]++;
            }
        }
        for ( int i = 0 ; i < n; i++){
            if (in[i] == 0) {
                // cout << i << "\n";
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int top = q.front();q.pop();
            ans.push_back(top);
            for ( int ne : edges[top]){
                in[ne]--; 
                if ( in[ne] == 0 )q.push(ne);
            }
        }
        
        sort( ans.begin(), ans.end());
        return ans;
    }
};
