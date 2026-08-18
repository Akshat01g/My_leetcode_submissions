class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& a, int k) {
        int n=a.size();
        bool fl=true;
        vector<vector<int>>ans;
        sort(a.begin(),a.end());
        for(int i=2;i<n;i+=3){
            if((a[i]-a[i-2])>k){
                fl=false;
            }
            else{
                ans.push_back({a[i-2],a[i-1],a[i]});
            }
        }
        // if(n%2==1){
        //     if(a[n-1]-a[n-3]>k){
        //         fl=false;
        //     }
        //     else{
        //         ans.push_back({a[n-3],a[n-2],a[n-1]});
        //     }
        // }
        if(!fl){
            return {};
        }
        else{
            return ans;
        }
    }
};