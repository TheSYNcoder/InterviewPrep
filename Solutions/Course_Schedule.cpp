#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
   // using bfs
    bool isBipartite(vector<vector<int>>&adj,int N,int node,vector<int>&color){
        queue<int>q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int ele:adj[curr]){
                if(color[ele] == color[curr]){ //bipartite cannot have two adjacent nodes of same color
                    return false;
                }
                if(color[ele]==-1){
                    color[ele]=1-color[curr];
                    q.push(ele);
                }
            }
        }
      return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        //Making adjacency list
        vector<vector<int>>adj(N+1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        // a color array
        // -1:not visited, 1: denotes first color set, 0: denotes second color set
        vector<int>color(N+1,-1);
        for(int i=0;i<N;i++){
            if(color[i]==-1){
                if(!isBipartite(adj,N,i,color))
                    return false;
            }
        }
        return true;
    }
};