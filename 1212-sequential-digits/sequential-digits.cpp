class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string s="123456789";
        for(int i=2;i<10;i++){
            for(int j=0;j<10-i;j++){
                int x=stoi(s.substr(j,i));
                if(low<=x && high>=x){
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};