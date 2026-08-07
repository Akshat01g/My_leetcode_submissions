class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        if(n==1){
            return 0;
        }
        vector<int>pre(n,0),suff(n,0);
        int mn=a[0];
        for(int i=1;i<n;i++){
            mn=min(mn,a[i]);
            pre[i]=max(pre[i-1],a[i]-mn);
        }
        int mx=a[n-1];
        for(int i=n-2;i>=0;i--){
            mx=max(mx,a[i]);
            suff[i]=max(suff[i+1],mx-a[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,pre[i]+suff[i]);
        }
        return ans;

    }
};