class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& a) {
        int n=a.size();
        int x=a[0][0]-a[1][0];
        int y=a[0][1]-a[1][1];
        
        for(int i=2;i<n;i++){
            int tx=a[i][0]-a[i-1][0];
            int ty=a[i][1]-a[i-1][1];
            if(ty*x!=y*tx){
                return false;
            }
        }
        return true;


    }
};