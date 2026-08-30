class Solution {
public:
    int minimumDeletions(vector<int>& a) {
        int n=a.size();
        if(n==1){
            return 1;
        }
        int mn=1e6;
        int mx=-1e6;
        for(int i=0;i<n;i++){
            if(a[i]<mn){
                mn=a[i];

            }
            if(a[i]>mx){
                mx=a[i];
            }
        }
        int mni=-1;
        int mxi=-1;
        for(int i=0;i<n;i++){
            if(a[i]==mn && mni==-1){
                mni=i+1;
            }
            if(a[i]==mx && mxi==-1){
                mxi=i+1;
            }
        }
        if(mni<mxi){
            return min({mxi,mni+n-mxi+1,n-mni+1});
        }
        else{
            return min({mni,mxi+n-mni+1,n-mxi+1});
        }
    }
};