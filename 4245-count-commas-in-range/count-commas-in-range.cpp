class Solution {
public:
    int countCommas(int n) {
        if(n<1000){
            return 0;
        }
        if(n==1000){
            return 1;
        }
        int ans=0;
        int x=1000;
        while(x<n){
            
            ans++;
            x*=1000;
        }
        if(n!=x/1000){
            ans+=(n-x/1000);
        }
        return ans;
    }
};