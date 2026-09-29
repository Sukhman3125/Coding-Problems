class Solution {
private:
    int pack(const int& a, const int& b) { return (a << 7) | b; }

    pair<int, int> unpack(const int& x) { return {x >> 7, x & ((1 << 7) - 1)}; }

    int sum(const int& x) {
        auto [a, b] = unpack(x);
        return a + b;
    }

    int sgn(const int& x) {
        if (x == 0)
            return 0;
        return x / (abs(x));
    }

public:
    int stoneGameVI(vector<int>& a, const vector<int>& b) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            a[i] = pack(a[i], b[i]);
        }
        sort(a.begin(), a.end(), [&](const int& a1, const int& b1) {
            return sum(a1) > sum(b1);
        });
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