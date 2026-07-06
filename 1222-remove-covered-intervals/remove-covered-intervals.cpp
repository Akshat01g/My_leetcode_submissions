class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        int n=a.size();
        int ans=0;
        int e=0;
        sort(a.begin(),a.end(),[](vector<int>& x,vector<int>& y){
            if(x[0]==y[0]) return x[1]>y[1];
            return x[0]<y[0];
        });
        for(int i=0;i<n;i++){
            if(a[i][1]>e){
                ans++;
                e=a[i][1];
            }
        }
        return ans;
    }
};