class Solution {
public:
    bool fun(int st,int n,vector<vector<int>>& adj,vector<int>&col){
        queue<int>qu;
        qu.push(st);
        col[st]=0;
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            for(int x:adj[node]){
                if(col[x]==-1){
                    if(col[node]==0){
                        col[x]=1;
                    }
                    else{
                        col[x]=0;
                    }
                    qu.push(x);
                }
                else{
                    if(col[x]==col[node]){
                        return false;
                    }
                }

            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!fun(i,n,adj,col)){
                    return false;
                }
            }
        }
        return true;
        

    }
};