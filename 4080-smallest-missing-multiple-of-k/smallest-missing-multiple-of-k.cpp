class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool>vis(101,false);
        int n=nums.size();
        for(int i=0;i<n;i++){
            vis[nums[i]]=true;
        }
        int x=k;
        while(x<101){
            if(!vis[x]){
                return x;
            }
            x+=k;
        }
        return x;
        

    }
};