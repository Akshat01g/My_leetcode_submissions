class Solution {
public:
    int ans;
    void solve(vector<int>&tasks,int t,int ind,vector<int>&a){
        if(a.size()>=ans){
            return;
        }
        if(ind==tasks.size()){
            ans=min(ans,(int)a.size());
            return;
        }
        for(int i=0;i<a.size();i++){
            if(a[i]+tasks[ind]<=t){
                a[i]+=tasks[ind];
                solve(tasks,t,ind+1,a);
                a[i]-=tasks[ind];


            }
        }
        a.push_back(tasks[ind]);
        solve(tasks,t,ind+1,a);
        a.pop_back();


    }
    int minSessions(vector<int>& tasks, int t) {
        int n=tasks.size();
        ans=tasks.size();
        vector<int>a;
        sort(tasks.begin(),tasks.end(),greater<int>());
        solve(tasks,t,0,a);
        return ans;
    }
};