class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        if(n<=2){
            return n;
        }
        for(int j=1;j<n;j++){
            if(i<n && j<n && nums[i]==nums[j]){
                if(i+1<n){
                    nums[i+1]=nums[j];
                    i++;
                }
                while(j+1<n && nums[i]==nums[j+1]){
                    j++;
                    
                }
            }
            else if(i<n && j<n && nums[i]!=nums[j]){
                if(i<n-1){
                    nums[i+1]=nums[j];
                    i++;
                }
            }
        }
        // if(nums[i-1]==nums[i] && nums[i]!=nums[n-1]){
        //     if(i+1<n){
        //         i++;
        //         nums[i]=nums[n-1];
        //     }
        // }
        // if(nums[i-1] !=nums[i] && nums[i]!=nums[n-1]){
        //     if(i+1<n){
        //         i++;
        //         nums[i]=nums[n-1];
        //     }
        // }
        return i+1;
    }
};