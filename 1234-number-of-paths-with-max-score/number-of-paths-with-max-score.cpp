class Solution {
public:
    int mod=1e9+7;
    pair<int,int> dfs(int r,int c,vector<string>&g,vector<vector<bool>>&vis,vector<vector<int>>&dp,vector<vector<int>>&way){
        int n=g.size();
        if(r>=n || c>=n || g[r][c]=='X'){
            return {-1,0};
        }
        if(r==n-1 && c==n-1){
            return {0,1};
        }
        if(vis[r][c]==true){
            return {dp[r][c],way[r][c]};
        }
        vis[r][c]=true;
        auto rt=dfs(r,c+1,g,vis,dp,way);
        auto dw=dfs(r+1,c,g,vis,dp,way);
        auto dia=dfs(r+1,c+1,g,vis,dp,way);
        int best=max({rt.first,dw.first,dia.first});
        if(best==-1){
            dp[r][c]=-1;
            way[r][c]=0;
            return {-1,0};
        }
        long long ways=0;
        if(rt.first==best){
            ways+=rt.second;
        }
        if(dw.first==best){
            ways+=dw.second;
        }
        if(dia.first==best){
            ways+=dia.second;
        }
        int val=0;
        if(g[r][c]>='0' && g[r][c]<='9'){
            val=g[r][c]-'0';
        }
        dp[r][c]=best+val;
        way[r][c]=ways%mod;
        return {dp[r][c], way[r][c]};


    }
    vector<int> pathsWithMaxScore(vector<string>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>dp(n,vector<int>(n,-2));
        vector<vector<int>>way(n,vector<int>(n,0));
        auto ans= dfs(0,0,g,vis,dp,way);
        if(ans.first==-1){
            return {0,0};
        }
        return {ans.first,ans.second};
    }
};