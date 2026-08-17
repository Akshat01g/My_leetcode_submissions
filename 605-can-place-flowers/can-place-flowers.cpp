class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        int sz=a.size();
        if(sz==1){
            if(a[0]==1 && n==0){
                return true;
            }
            else if(a[0]==0 && n==1){
                return true;
            }
            else if(a[0]==0 && n==0){
                return true;
            }
            else{
                return false;
            }
        }
        if(a[0]==0 && a[1]==0){
            n--;
            a[0]=1;
        }
        for(int i=1;i<sz-1;i++){
            if(a[i-1]==0 && a[i]==0 && a[i+1]==0){
                n--;
                a[i]=1;
            }
        }
        if(a[sz-1]==0 && a[sz-2]==0){
            n--;
            a[sz-1]=1;
        }
        if(n>0){
            return false;
        }
        else{
            return true;
        }
    }
};