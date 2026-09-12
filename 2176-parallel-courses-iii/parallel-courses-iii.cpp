class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n+1);
        for(auto it:relations){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int>indegree(n+1);
        for(auto &it:adj){
            for(int i=0;i<it.size();i++){
                indegree[it[i]]++;
            }
        }
        vector<int>temp(n+1,0);
        queue<int>qu;
        for(int i=1;i<n+1;i++){
            if(indegree[i]==0){
                qu.push(i);
                temp[i]=time[i-1];
            }
        }
        int ans=0;

        while(!qu.empty()){
            auto it=qu.front();
            qu.pop();
            ans=max(ans,temp[it]);
            for(auto &x:adj[it]){
                temp[x]=max(temp[x],temp[it]+time[x-1]);
                indegree[x]--;
                if(indegree[x]==0){
                    qu.push(x);
                }
            }
        }
        return ans;
        

    }
};