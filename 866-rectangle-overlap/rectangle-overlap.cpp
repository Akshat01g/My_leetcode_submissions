class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int mxx1=max(rec1[0],rec1[2]);
        int mxy1=max(rec1[1],rec1[3]);
        int mnx1=min(rec1[0],rec1[2]);
        int mny1=min(rec1[1],rec1[3]);

        int mnx2=min(rec2[0],rec2[2]);
        int mny2=min(rec2[1],rec2[3]);
        int mxx2=max(rec2[0],rec2[2]);
        int mxy2=max(rec2[1],rec2[3]);
        if(mxx1<=mnx2 ||  mxy1<=mny2 || mxx2<=mnx1 ||  mxy2<=mny1){
            return false;
        }
        return true;

    }
};