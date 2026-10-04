class Solution {
private:
    static inline int dp[100][100];

public:
    bool checkValidString(string& s, int i = 0, int stck = 0) {
        if (i == s.size())
            return stck == 0;
        if (dp[i][stck] != -1)
            return dp[i][stck];
        if (s[i] == '(') {
            return dp[i][stck] = checkValidString(s, i + 1, stck + 1);
        }
        if (s[i] == ')') {
            if (stck == 0)
                return false;
            return dp[i][stck] = checkValidString(s, i + 1, stck - 1);
        }
        // *
        bool open = checkValidString(s, i + 1, stck + 1);
        bool closed = stck == 0 ? false : checkValidString(s, i + 1, stck - 1);
        bool empt = checkValidString(s, i + 1, stck);
        return dp[i][stck] = open | closed | empt;
    }

    Solution() {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                dp[i][j] = -1;
            }
        }
    }
};