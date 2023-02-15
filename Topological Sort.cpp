class Solution
{
    void solve(vector<int> adj[],vector<int>&s,unordered_map<int,bool>&vist,int node){
        vist[node]=true;
        for(auto nbr:adj[node]){
            if(!vist[nbr]){
                solve(adj,s,vist,nbr);
            }
        }
        s.push_back(node);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
	    unordered_map<int,bool>vist;
	    for(int i=0;i<V;i++){
	        if(!vist[i]){
	            solve(adj,ans,vist,i);
	        }
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};