class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int mod=1e9+7;
        int mx=201;
        vector<vector<int>>dp(mx,vector<int>(mx,0));
        dp[0][0]=1;
        for(auto x:nums){
            vector<vector<int>>temp=dp;
            for(int g1=0;g1<mx;g1++){
                for(int g2=0;g2<mx;g2++){
                    if(dp[g1][g2]==0){
                        continue;
                    }
                    int a=x,b=x;
                    if(g1!=0){
                        a=gcd(g1,x);
                    }
                    if(g2!=0){
                        b=gcd(x,g2);
                    }
                    temp[a][g2]=(temp[a][g2]+dp[g1][g2])%mod;
                    temp[g1][b]=(temp[g1][b]+dp[g1][g2])%mod;
                }
                
            }
            dp=temp;
        }
        int ans=0;
        for(int i=1;i<mx;i++){
            ans=(ans%mod+dp[i][i]%mod)%mod;
        }
        return ans;
    }
};