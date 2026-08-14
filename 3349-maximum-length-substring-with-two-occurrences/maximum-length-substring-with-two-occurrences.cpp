class Solution {
public:
    int maximumLengthSubstring(string s) {
        int mx=0;
        for(int i=0;i<s.size();i++){
            int len=0;
            vector<int>freq(26,0);
            for(int j=i;j<s.size();j++){
                freq[s[j]-'a']++;
                if(freq[s[j]-'a']>2){
                    break;
                }
                len=j-i+1;
            }
            mx=max(mx,len);
        }
        return mx;
    }
};