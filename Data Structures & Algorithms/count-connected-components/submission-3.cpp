class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<bool>>adj(n,vector<bool>(n,false));

        for(auto v:edges){
            adj[v[0]][v[1]]=true;
            adj[v[1]][v[0]]=true;
        }

        vector<bool>vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
            count++;
            dfs(adj,vis,i,n);
            }
        }
        return count;
    }
    void dfs(vector<vector<bool>>&adj,vector<bool>&vis,int node,int n){
        vis[node]=true;
        
        for(int i=0;i<n;i++){
            if(adj[node][i]==true && vis[i]==false){
                dfs(adj,vis,i,n);
            }
        }
    }
};
