class Solution {
public:
    int maxDigitRange(vector<int>& a) {
        int n=a.size();
        vector<int>dr(n,0);
        for(int i=0;i<n;i++){
            int x=a[i];
            int largest=INT_MIN;
            int smallest=INT_MAX;
            while(x>0){
                largest=max(largest,x%10);
                smallest=min(smallest,x%10);
                x/=10;
            }
            if(largest!=INT_MIN && smallest!=INT_MAX)dr[i]=(largest-smallest);


        }
        int ans=0;
        int mx=*max_element(dr.begin(),dr.end());
        for(int i=0;i<n;i++){
            if(dr[i]==mx){
                ans+=a[i];
            }
        }
        return ans;
    }
};