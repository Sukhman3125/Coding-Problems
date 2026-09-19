class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        if(xc>=x1 && xc<=x2 && yc>=y1 && yc<=y2) return true; // center inside rect
        int x = max(x1, min(xc, x2));
        int y = max(y1, min(yc, y2)); // closest pt to circle from rect
        int distSq = (x-xc)*(x-xc) + (y-yc)*(y-yc);
        return distSq <= r*r; 
    }
};