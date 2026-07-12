class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        map<int,vector<int>>mp;
        set<int>st;
        for(int i=0;i<a.size();i++){
            mp[a[i]].push_back(i);
            st.insert(a[i]);
        }
        vector<int>ans(a.size(),0);
        int rank=0;
        while(!st.empty()){
            int x=*st.begin();
            st.erase(st.begin());
            rank++;
            for(auto &w:mp[x]){
                ans[w]=rank;
            }
        }
        return ans;


    }
};