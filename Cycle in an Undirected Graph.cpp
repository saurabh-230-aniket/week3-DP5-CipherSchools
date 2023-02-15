bool dfs(int par,int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(node,it,vis,adj)){
                    return 1;
                }
            }
            else if(it!=par){
                return 1;
            }
                
            }
            return 0;
        }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0)
            {
                if(dfs(-1,i,vis,adj)){
                    return 1;
                }
            }
        }
        return 0;
    }
};