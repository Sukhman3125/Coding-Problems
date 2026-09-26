class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(source == target) return 0;
        int r1 = source[0], c1 = source[1], r2 = target[0], c2 = target[1];
        if(r1 == r2) return 1;
        if(c1 == c2) return 1;
        if(abs(r1-r2) == abs(c1-c2)) return 1;
        return 2;
    }
};