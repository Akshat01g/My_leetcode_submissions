class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        if(n<2){
            return 0;
        }
        vector<int>pre(n),suf(n);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=gcd(pre[i-1],nums[i]);
            suf[n-i-1]=gcd(suf[n-i],nums[n-i-1]);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(pre[i]==suf[i+1]){
                ans++;
            }
        }
        for(int i=0;i<n;i++){
            vector<int>b;
            for(int j=0;j<n;j++){
                if(i!=j){
                    b.push_back(nums[j]);
                }
            }
            int sz=b.size();
            vector<int>pre(sz),suf(sz);
            pre[0]=b[0];
            suf[sz-1]=b[sz-1];
            for(int i=1;i<sz;i++){
                pre[i]=gcd(pre[i-1],b[i]);
                suf[sz-i-1]=gcd(suf[sz-i],b[sz-i-1]);
            }
            int curr=0;
            for(int i=0;i<sz-1;i++){
                if(pre[i]==suf[i+1]){
                    curr++;
                }
            }
            ans=max(ans,curr);

        }
        return ans;

    }
};