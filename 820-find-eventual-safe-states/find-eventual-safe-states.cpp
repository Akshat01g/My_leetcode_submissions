class Solution {
public:
    bool dfs(int i,vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&pathvis,vector<bool>&check){
        vis[i]=true;
        pathvis[i]=true;
        for(auto x:adj[i]){
            if(!vis[x]){
                if(dfs(x,adj,vis,pathvis,check)){
                    return true;
                }
            }
            else if(pathvis[x]){
                return true;
            }
        }
        check[i]=true;
        pathvis[i]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<bool>vis(V,false);
        vector<bool>pathvis(V,false);
        vector<bool>check(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pathvis,check);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};