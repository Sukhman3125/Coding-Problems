class Solution {
private:
    int pack(int& a, int& b) { return (a << 7) | b; }

    pair<int, int> unpack(int& x) { 
        return {x >> 7, x & ((1 << 7) - 1)}; 
    }

    int sum(int& x) {
        auto [a, b] = unpack(x);
        return a + b;
    }

    int sgn(int x){
        if(x==0) return 0;
        return x/(abs(x));
    }

public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            a[i] = pack(a[i], b[i]);
        }
        sort(a.begin(), a.end(),
             [&](int& a1, int& b1) { return sum(a1) > sum(b1); });
        int score = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                score += unpack(a[i]).first;
            } else {
                score -= unpack(a[i]).second;
            }
        }

        return sgn(score);
    }
};