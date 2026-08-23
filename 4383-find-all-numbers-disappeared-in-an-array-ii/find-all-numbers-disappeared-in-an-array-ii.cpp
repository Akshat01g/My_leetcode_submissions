class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& a, int lower, int upper) {
        int n=a.size();
        vector<vector<int>>ans;
        vector<int>temp;
        temp.push_back(lower-1);
        for(int i=0;i<n;i++){
            if(a[i]>lower && a[i]<upper){
                temp.push_back(a[i]);
            }
            else if(a[i]==lower || a[i]==upper){
                temp.push_back(a[i]);
            }
        }
        temp.push_back(upper+1);
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        for(int i=1;i<temp.size();i++){
            int l=temp[i-1]+1;
            int r=temp[i]-1;
            if(l<=r){
                ans.push_back({l,r});
            }


        }
        return ans;
    }
};