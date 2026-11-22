class Solution {
public:
    int minRange(int a, int b, int c) {
        int x = min({a,b,c});
        int z = max({a,b,c});
        int y = a+b+c-x-z;
        return min(y, z-x);
    }
};