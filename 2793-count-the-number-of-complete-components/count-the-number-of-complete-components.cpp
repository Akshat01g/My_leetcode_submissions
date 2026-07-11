class Solution {
public:
    int nodes,edge;
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis){
        vis[node]=true;
        nodes++;
        edge+=adj[node].size();
        for(auto x:adj[node]){
            if(!vis[x]){
                dfs(x,adj,vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                nodes=0;
                edge=0;
                dfs(i,adj,vis);
                edge/=2;
                if(edge==nodes*(nodes-1)/2){
                    ans++;
                }
            }
        }
        return ans;
    }
};