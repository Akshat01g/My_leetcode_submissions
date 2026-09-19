class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long long>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];

        }
        int ans=0;
        for(int i=0;i<n;i++){
            int l=0;
            int r=i;
            int s=i;
            int mid=l+(r-l)/2;
            while(l<=r){
                long long len=(i-mid+1);
                long long tn=len*nums[i];
                long long sum=0;
                if(mid==0){
                    sum=pre[i];

                }
                else{
                    sum=pre[i]-pre[mid-1];
                }
                int cost=tn-sum;
                if(cost>k){
                    l=mid+1;
                }
                else{
                    s=mid;
                    r=mid-1;
                }
                mid=l+(r-l)/2;
            }
            ans=max(ans,i-s+1);
        }
        return ans;
    }
};