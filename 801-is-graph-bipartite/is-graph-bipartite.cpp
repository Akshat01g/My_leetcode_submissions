class Solution {
public:
    bool dfs(int st,int pre,vector<vector<int>>& adj,vector<int>&col){
        if(pre==-1 || pre==1){
            col[st]=0;
        }
        else{
            col[st]=1;
        }
        for(auto x:adj[st]){
            if(col[x]==-1){
                if(!dfs(x,col[st],adj,col)){
                    return false;
                }
            }
            else if(col[x]==col[st]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!dfs(i,-1,adj,col)){
                    return false;
                }
            }
        }
        return true;
        

    }
};