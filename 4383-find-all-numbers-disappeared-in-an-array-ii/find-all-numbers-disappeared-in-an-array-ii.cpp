class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& a, int lower, int upper) {
        int n=a.size();
        vector<vector<int>>ans;
        if(n==0){
            ans.push_back({lower,upper});
            return ans;
        }
        sort(a.begin(),a.end());
        
        if(a[n-1]<lower){
           ans.push_back({lower,upper});
           return ans;
        }
        int i=0;
        while(i<n && a[i]<lower){
            i++;
        }
        if(i==n){
            ans.push_back({lower,upper});
           return ans;
        }
        if(a[i]>lower){
            ans.push_back({lower,min(a[i]-1,upper)});
        }
        
        // if(i+1<n && a[i]==lower ){
        //     ans.push_back({lower+1,a[i+1]-1});
        // }
        // else if(i+1==n && a[i]==lower){
        //     ans.push_back({lower+1,upper});
        //     return ans;
        // }
        // else if(a[i]>lower){
        //     ans.push_back({lower,a[i]-1});
        // }
        int prev=a[i];
        if(i==0){
            i++;
        }
        
        for(;i<n;i++){
            if(a[i]>upper){
                break;
            }
            if(a[i]-prev>1){
                ans.push_back({prev+1,a[i]-1});
            }
            prev=a[i];
        }
        if(upper>prev){
            ans.push_back({prev+1,upper});
        }
        return ans;
    }
};