class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>st;
        for(int i=0;i<a.size();i++){
            if(i==0 || a[i]>0){
                st.push(a[i]);
            }
            else if(a[i]<0){
                int x=-a[i];
                while(!st.empty() && st.top()>0 && x>st.top()){
                    st.pop();
                }
                if(!st.empty() && st.top()==x){
                    st.pop();
                }
                else if(st.empty() || st.top()<0)st.push(a[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};