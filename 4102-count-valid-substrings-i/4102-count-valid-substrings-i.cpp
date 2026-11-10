class Solution {
public:
    long long countValidSubstrings(string s) {
        long long containing = 0;
        int last = -1;
        int n = s.size();

        for (int i = 2; i < n; i++) {
            if (s.substr(i - 2, 3) == "abc")
                last = i - 2;

            containing += last + 1;
        }

        return 1LL * n * (n + 1) / 2 - containing;
    }
};