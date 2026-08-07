class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int mn=a[0];
        int ans=0;
        for(int i=1;i<n;i++){
            if(a[i]>mn){
                ans+=(a[i]-mn);
                
            }
            mn=a[i];

            
        }
        return ans;
    }
};