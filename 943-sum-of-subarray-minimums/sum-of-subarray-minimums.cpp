class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        int n=a.size();
        int mod=1e9+7;
        long long ans=0;
        stack<int>st;
        vector<int>l(n),r(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&& a[st.top()]>=a[i]){
                st.pop();
            }
            int left=-1;
            if(!st.empty()){
                left=st.top();
            }
            l[i]=left;
            st.push(i);
        }
        while(!st.empty()){
            st.pop();

        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& a[st.top()]>a[i]){
                st.pop();
            }
            int right=n;
            if(!st.empty()){
                right=st.top();
            }
            r[i]=right;
            st.push(i);
        }
        for(int i=0;i<n;i++){
            int lc=i-l[i];
            int rc=r[i]-i;
            ans=(ans+a[i]*1LL*lc*rc)%mod;
        }
        ans%=mod;
        return ans;
    }
};