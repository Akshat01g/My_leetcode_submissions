class Solution {
    int mod=1e9+7;
public:
    int solve(int i,int j,string &s,vector<vector<int>>&dp){
        if(i==0)return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i-1]-'a'==j){
            int sum=1;
            for(int k=0;k<26;k++){
                sum=(sum%mod+solve(i-1,k,s,dp)%mod)%mod;;
            }
            return dp[i][j]=sum;

        }
        return dp[i][j]=solve(i-1,j,s,dp);
    }
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(26,-1));
        int ans=0;
        for(int j=0;j<26;j++){
            ans=(ans%mod+solve(n,j,s,dp)%mod)%mod;
        }
        return ans;
    }
};