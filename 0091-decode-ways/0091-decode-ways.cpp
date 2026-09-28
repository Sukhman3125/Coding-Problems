class Solution {
private:
    int n;
    vector<vector<int>> dp;

    int recur(string& s, char prev = '\0', int i = 0) {
        if (i == n) {
            return prev == '\0' ? 1 : 0;
        }

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int ans = 0;

        if (prev != '\0') {
            int num = (prev - '0') * 10 + (s[i] - '0');

            if (num >= 10 && num <= 26)
                ans = recur(s, '\0', i + 1);

            return dp[i][prev + 1] = ans;
        }

        if (s[i] >= '1' && s[i] <= '9') {
            ans += recur(s, '\0', i + 1);
        }

        if (s[i] == '1' || s[i] == '2') {
            ans += recur(s, s[i], i + 1);
        }

        return dp[i][prev + 1] = ans;
    }

public:
    int numDecodings(string s) {
        n = s.size();
        dp.assign(n, vector<int>(257, -1));

        return recur(s);
    }
};