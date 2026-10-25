class Solution {
private:
    int bitCnt(int x) {
        int cnt = 0;
        while (x) {
            if ((x & 1) == 1)
                cnt++;
            x /= 2;
        }
        return cnt;
    }

public:
    int calculateScore(int a, int b) {
        int s1 = bitCnt(a), s2 = bitCnt(b);
        if (s1 >= s2)
            return s1 * s2;
        return s2 / s1;
    }
};