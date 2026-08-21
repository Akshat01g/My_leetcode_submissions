class Solution {
public:
    bool fun(int n){
        if(n<2){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        int f=-1,l=-1;
        for(int i=0;i<n;i++){
            if( fun(nums[i]) && f==-1){
                f=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(fun(nums[i]) && l==-1){
                l=i;
                break;
            }
        }
        if(f==-1){
            return 0;
        }
        return l-f;
        
    }
};