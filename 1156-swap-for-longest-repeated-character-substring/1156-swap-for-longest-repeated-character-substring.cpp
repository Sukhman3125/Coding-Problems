class Solution {
public:
    int maxRepOpt1(string text) {
        vector<pair<char, int>> s;

        char curr = '\0';
        int f = 0;

        for (char it : text) {
            if (it == curr) {
                f++;
            } else {
                if (f != 0)
                    s.push_back({curr, f});

                curr = it;
                f = 1;
            }
        }

        if (f != 0)
            s.push_back({curr, f});

        unordered_map<char, int> total;
        for (auto [c, cnt] : s)
            total[c] += cnt;

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i].first;
            int cnt = s[i].second;

            ans = max(ans, min(cnt + 1, total[c]));

            if (i + 2 < s.size() &&
                s[i + 1].second == 1 &&
                s[i + 2].first == c) {

                int combined = cnt + s[i + 2].second;

                ans = max(ans, min(combined + 1, total[c]));
            }
        }

        return ans;
    }
};