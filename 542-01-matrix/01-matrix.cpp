class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>qu;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    qu.push({{i,j},0});
                    vis[i][j]=true;
                }
                else{
                    vis[i][j]=false;
                }
            }
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!qu.empty()){
            auto x=qu.front().first.first;
            auto y=qu.front().first.second;
            auto dis=qu.front().second;
            qu.pop();
            dist[x][y]=dis;
            for(int k=0;k<4;k++){
                auto nr=x+dx[k];
                int nc=y+dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    vis[nr][nc]=true;
                    qu.push({{nr,nc},dis+1});
                    
                }
            }
            
        }
        return dist;
    }
};