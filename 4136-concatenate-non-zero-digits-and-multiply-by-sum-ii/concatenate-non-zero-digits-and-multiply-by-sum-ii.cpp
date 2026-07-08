class Solution {
public:
    int mod=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        int n=s.size();
        vector<int>d,p;
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                d.push_back(s[i]-'0');
                p.push_back(i);
            }
        }
        int i=d.size();
        vector<long long>power(i+1,1),pre(i+1,0),preval(i+1,0);
        for(int j=1;j<=i;j++){
            power[j]=(power[j-1]*10)%mod;
        }
        for(int j=0;j<i;j++){
            pre[j+1]=pre[j]+d[j];
        }
        for(int j=0;j<i;j++){
            preval[j+1]=(preval[j]*10+d[j])%mod;
        }
        vector<int>ans(q.size(),0);
        int cnt=0;
        for(auto x:q){
            int l=x[0];
            int r=x[1];
            int left=lower_bound(p.begin(),p.end(),l)-p.begin();
            int right=upper_bound(p.begin(),p.end(),r)-p.begin()-1;
            if(left>right){
                cnt++;
                continue;
            }
            long long sum=pre[right+1]-pre[left];
            long long num=preval[right+1];
            long long rem=(preval[left]*power[right-left+1])%mod;
            num=(num-rem+mod)%mod;
            ans[cnt]=(num*(sum%mod))%mod;
            cnt++;
        }
        return ans;



    }
};