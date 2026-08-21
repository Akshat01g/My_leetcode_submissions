class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        for(int i=0;i<n;i++){
            vector<bool>col(n,false);
            vector<bool>row(n,false);
            for(int j=0;j<n;j++){
                if(row[matrix[i][j]-1]){
                    return false;
                }
                if(col[matrix[j][i]-1]){
                    return false;
                }
                row[matrix[i][j]-1]=true;
                col[matrix[j][i]-1]=true;
            }
        }
        return true;
    }
};