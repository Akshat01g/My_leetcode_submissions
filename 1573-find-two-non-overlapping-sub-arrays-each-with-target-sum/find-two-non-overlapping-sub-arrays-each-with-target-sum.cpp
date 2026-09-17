class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int s=0;
        vector<int>a(n,INT_MAX);
        int ans=INT_MAX;
        int mx=INT_MAX,smx=INT_MAX;
        for(int j=0;j<n;j++){
            s+=arr[j];
            while(s>target){
                s-=arr[i];
                i++;
            }
            if(j>0){
                a[j]=a[j-1];
            }
            if(s==target){
                int len=j-i+1;
                if(i>0 && a[i-1]!=INT_MAX){
                    ans=min(ans,a[i-1]+len);
                }
                a[j]=min(a[j],len);
            }

        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};