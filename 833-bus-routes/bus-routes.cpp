class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& r, int s, int t) {
        if(s==t){
            return 0;
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<r.size();i++){
            for(auto x:r[i]){
                mp[x].push_back(i);
            }
        }
        queue<int>qu;
        vector<bool>vis(r.size(),false);
        for(auto x:mp[s]){
            qu.push(x);
            vis[x]=true;
        }
        int ans=1;
        while(!qu.empty()){
            int sz=qu.size();
            for(int i=0;i<sz;i++){
                int y=qu.front();
                qu.pop();
                for(auto x:r[y]){
                    if(x==t){
                        return ans;
                    }
                    for(auto z:mp[x]){
                        if(!vis[z]){
                            qu.push(z);
                            vis[z]=true;
                        }
                    }
                }
            }
            ans++;
        }
        return -1;

    }
};