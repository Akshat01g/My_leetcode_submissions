class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& g, int l) {
        int n=g[0].size();
        vector<int>dp(n,1);
        for(int c=0;c<n;c++){
            for(int i=c-1;i>=0;i--){
                if(dp[i]+1>dp[c]){
                    bool fl=true;
                    for(auto &x:g){
                        if(abs(x[c]-x[i])>l){
                            fl=false;
                            break;
                        }

                    }
                    if(fl){
                        dp[c]=dp[i]+1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
            }
        }
        return ans;
    }
};