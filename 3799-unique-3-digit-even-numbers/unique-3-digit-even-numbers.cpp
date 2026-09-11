class Solution {
public:

    int totalNumbers(vector<int>& a) {
        int n=a.size();
        vector<int>freq(10,0);
        for(int i=0;i<n;i++){
            freq[a[i]]++;
        }
        int ans=0;
        for(int i=100;i<1000;i+=2){
            int o=i%10;
            int t=(i/10)%10;
            int h=(i/100);
            freq[o]--;
            freq[t]--;
            freq[h]--;
            if(freq[o]>=0 && freq[t]>=0 && freq[h]>=0){
                ans++;
            }
            freq[o]++;
            freq[t]++;
            freq[h]++;
        }
        return ans;
    }
};