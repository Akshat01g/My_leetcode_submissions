class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int o=0,e=0;
        int mo=INT_MAX,me=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                o++;
                mo=min(mo,nums[i]);

            }
            else{
                e++;
                me=min(me,nums[i]);
            }
        }
        if(e==0 && o!=0){
            return true;
        }
        if(e!=0 && o==0){
            return true;
        }
        else if(e!=0 && o!=0 && me>mo){
            return true;
        }
        return false;
        
    }
};