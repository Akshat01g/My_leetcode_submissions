class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int x=max(x1,min(x2,xc))-xc;
        int y=max(y1,min(y2,yc))-yc;
        return x*x+y*y<=r*r;
    }
};