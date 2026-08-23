class Solution {
public:
    string fun(char c){
        string s="";
        for(int i=7;i>=0;i--){
            s+=((c>>i)&1);
        }
        return s;
    }
    bool isPalindromic(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            ans+=fun(s[i]);
        }
        int l=0,r=ans.size()-1;
        while(l<r){
            if(ans[l]==ans[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};