class Solution {
public:
    void dfs(int r,int c,vector<vector<bool>>&vis,vector<vector<char>>&g,int dx[],int dy[]){
        vis[r][c]=true;
        int n=g.size();
        int m=g[0].size();
        for(int k=0;k<4;k++){
            int nr=r+dx[k];
            int nc=c+dy[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && g[nr][nc]=='O'){
                dfs(nr,nc,vis,g,dx,dy);
            }
        }

    }
    void solve(vector<vector<char>>& g) {
        int n=g.size();
        int m=g[0].size();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int j=0;j<m;j++){
            if(!vis[0][j] && g[0][j]=='O'){
                dfs(0,j,vis,g,dx,dy);
            }
            if(!vis[n-1][j] && g[n-1][j]=='O'){
                dfs(n-1,j,vis,g,dx,dy);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && g[i][0]=='O'){
                dfs(i,0,vis,g,dx,dy);
            }
            if(!vis[i][m-1] && g[i][m-1]=='O'){
                dfs(i,m-1,vis,g,dx,dy);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && g[i][j]=='O'){
                    g[i][j]='X';
                }
            }
        }
    }
};