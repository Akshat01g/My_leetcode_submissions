class Solution {
public:
    long long fun(long long base,long long exp){
        long long ans=1;
        long long mod=1e9+7;
        while(exp>0){
            if(exp%2==0){
                base=(base*base)%mod;
                exp/=2;

            }
            else{
                ans=(ans*base)%mod;
                base=(base*base)%mod;
                exp/=2;
            }
        }
        return ans;

    }
    int sumDecoded(vector<long long>& a) {
        int n=a.size();
        long long ans=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++){
            long long width=a[i]%10;
            long long d=a[i]/10;
            string s=to_string(d);
            long long x=stoll(s.substr(0,width));
            long long y=stoll(s.substr(width)); 
            long long p=fun(x,y);
            ans=(ans+p)%(mod);

        }
        return int(ans);
    }
};