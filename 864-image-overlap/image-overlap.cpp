class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>>a,b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    a.push_back({i,j});
                }
                if(img2[i][j]==1){
                    b.push_back({i,j});
                }
            }
        }
        int ans=0;
        map<pair<int,int>,int>mp;
        for(auto &x:a){
            for(auto &y:b){
                int rd=x.first-y.first;
                int cd=x.second-y.second;
                mp[{rd,cd}]++;
                ans=max(ans,mp[{rd,cd}]);
            }
        }
        return ans;
    }
};