class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        if(s==t){
            return true;
        }
        int n=s.size();
        int m=t.size();
        if(n>m){
            return false;

        }
        vector<int>pre(n,-1),suf(n,-1);
        int j=0;
        for(int i=0;i<n && j<m;i++){
            while(j<m && s[i]!=t[j]){
                j++;
            }
            if(j==m){
                break;
            }
            pre[i]=j;
            j++;

        }
        if(pre[n-1]!=-1){
            return true;
        }
        j=m-1;
        for(int i=n-1;i>=0 && j>=0 ;i--){
            while(j>=0 && s[i]!=t[j]){
                j--;
            }
            if(j==-1){
                break;
            }
            suf[i]=j;
            j--;
        }
        for(int i=0;i<n;i++){
            int l=-1;
            if(i!=0){
                l=pre[i-1];
            }
            int r=m;
            if(i!=n-1){
                r=suf[i+1];
            }
            if(i>0 && l==-1){
                continue;
            }
            if(i<n-1 && r==-1){
                continue;
            }
            if(r-l>=2){
                return true;
            }

        }
        return false;

        



    }
};