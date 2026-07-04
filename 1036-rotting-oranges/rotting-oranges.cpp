class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>qu;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==2){
                    qu.push({{i,j},0});
                }
            }
        }
        vector<vector<int>>ans=g;
        int res=0;
        while(!qu.empty()){
            auto x=qu.front().first.first;
            auto y=qu.front().first.second;
            auto cost=qu.front().second;
            qu.pop();
            vis[x][y]=true;
            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            for(int k=0;k<4;k++){
                int nr=x+dx[k];
                int nc=y+dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && g[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=true;
                    ans[nr][nc]=2;
                    res=cost+1;
                    qu.push({{nr,nc},cost+1});

                }
            }


        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]==1){
                    return -1;
                }
            }
        }
        return res;

    }
};