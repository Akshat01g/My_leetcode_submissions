#define ll long long 
class Solution {
public:
    vector<int> gcdValues(vector<int>& a, vector<long long>& q) {
        int n=a.size();
        int mx=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mx=max(mx,a[i]);
            mp[a[i]]++;
        }
        vector<ll>b(mx+1,0);
        for(int i=mx;i>0;i--){
            ll cnt=0,lt=0;
            for(int j=i;j<=mx;j+=i){
                if(mp.find(j)!=mp.end()){
                    cnt+=mp[j];
                }
                lt+=b[j];
            }
            ll gt=(cnt*(cnt-1)/2)-lt;
            b[i]=gt;
        }
        vector<ll>pre;
        vector<ll>val;
        for(int i=1;i<=mx;i++){
            if(b[i]){
                ll p=0;
                if(pre.size()!=0){
                    p=pre.back();
                }
                p+=b[i];
                pre.push_back(p);
                val.push_back(i);
            }
        }
        vector<int>ans;
        for(auto it:q){
            int index=lower_bound(pre.begin(),pre.end(),it+1)-pre.begin();
            ans.push_back(val[index]);
        }
        return ans;

    }
};