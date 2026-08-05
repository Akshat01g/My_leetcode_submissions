class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n=a.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++){
            pq.push({a[i],i});
        }
        int w=1;
        vector<int>ans;
        ans.push_back(pq.top().first);
        for(int i=1;i<n-k+1;i++){
            pq.push({a[i+k-1],i+k-1});
            while(pq.top().second<i){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};