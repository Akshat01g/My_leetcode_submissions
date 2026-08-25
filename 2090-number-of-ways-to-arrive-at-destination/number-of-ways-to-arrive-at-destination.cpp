class Solution {
public:
    int countPaths(int sz, vector<vector<int>>& roads) {
        int n=roads.size();
        int mod=(1e9+7);
        vector<vector<pair<int,int>>>adj(sz);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>same(sz,0);
        vector<long long>dist(sz,LLONG_MAX);
        same[0]=1;
        dist[0]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long wt=it.first;
            int ind=it.second;
            if(wt>dist[ind]){
                continue;
            }
            for(auto x:adj[ind]){
                long long nw=(x.second+wt);
                if(nw<dist[x.first]){
                    dist[x.first]=nw;
                    same[x.first]=same[ind];
                    pq.push({nw,x.first});
                }
                else if(nw==dist[x.first]){
                    same[x.first]=(same[x.first]%mod+same[ind]%mod)%mod;
                }
            }
        }
        return same[sz-1]%mod;
    }
};