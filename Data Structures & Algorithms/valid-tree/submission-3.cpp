class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        if(edges.size()!=(n-1))
            return false;

        vector<vector<bool>>adj(n,vector<bool>(n,false));

        for(auto v:edges){
            adj[v[0]][v[1]]=true;
            adj[v[1]][v[0]]=true;
        }

        vector<bool>vis(n,false);

        dfs(adj,vis,0,n);

        for(int i=0;i<n;i++){
            if(!vis[i])
                return false;
        }
        return true;
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
