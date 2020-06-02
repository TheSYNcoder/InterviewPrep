#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isCyclic(vector<vector<int>>&adj,vector<int>&visited,int current){
        if(visited[current]==2)
            return true;
        visited[current]=2;
        for(int i=0;i<adj[current].size();i++){
            if(visited[adj[current][i]]!=1){
                if(isCyclic(adj,visited,adj[current][i]))
                    return true;
            }
        }
        visited[current]=1;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(isCyclic(adj,visited,i)){
                    return false;
                }
            }
        }
        return true;
    }
};