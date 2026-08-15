class Solution {
public:
    int longestSubsequence(vector<int>& a) {
        int n=a.size();
        bool zero=true;
        for(int i=0;i<n;i++){
            if(a[i]!=0){
                zero=false;
            }
        }
        if(zero){
            return 0;
        }
        sort(a.begin(),a.end());
        int xr=0;
        for(int i=0;i<n;i++){
            xr^=a[i];
        }
        if(xr==0){
            return n-1;
        }
        else{
            return n;
        }
    }
};