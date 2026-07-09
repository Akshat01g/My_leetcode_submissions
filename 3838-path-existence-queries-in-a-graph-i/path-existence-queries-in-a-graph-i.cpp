class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int diff, vector<vector<int>>& qu) {
        vector<int>grp(n,0);
        int cur=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>diff){
                cur++;
            }
            grp[i]=cur;
        }
        vector<bool>ans(qu.size(),false);
        int i=0;
        for(auto q:qu){
            if(grp[q[0]]==grp[q[1]]){
                ans[i]=true;
            }
            i++;
        }
        return ans;


    }
};