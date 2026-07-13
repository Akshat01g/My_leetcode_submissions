class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<vector<int>>adjrev(V);
        vector<int>ans,indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                adjrev[x].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>qu;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                qu.push(i);
            }
        }
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            ans.push_back(node);
            for(auto x:adjrev[node]){
                indegree[x]--;
                if(indegree[x]==0){
                    qu.push(x);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};