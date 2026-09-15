class Solution {
private:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        if (k == 1)
            return n;

        vector<pair<int, int>> palins;

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            int l = i - 1, r = i + 1;

            while (l >= 0 && r < n) {
                if (s[l] != s[r])
                    break;

                if (r - l + 1 >= k) {
                    palins.push_back({l, r});
                    break;
                }

                l--;
                r++;
            }

            // Even length palindrome: center between i-1 and i
            l = i - 1;
            r = i;

            while (l >= 0 && r < n) {
                if (s[l] != s[r])
                    break;

                if (r - l + 1 >= k) {
                    palins.push_back({l, r});
                    break;
                }

                l--;
                r++;
            }

            // Even length palindrome: center between i and i+1
            l = i;
            r = i + 1;

            while (l >= 0 && r < n) {
                if (s[l] != s[r])
                    break;

                if (r - l + 1 >= k) {
                    palins.push_back({l, r});
                    break;
                }

                l--;
                r++;
            }
        }

        // Classic interval scheduling:
        // choose intervals with the earliest ending position.
        sort(palins.begin(), palins.end(),
             [](const auto& a, const auto& b) {
                 return a.second < b.second;
             });

        int ans = 0;
        int lastEnd = -1;

        for (auto& [l, r] : palins) {
            if (l > lastEnd) {
                ans++;
                lastEnd = r;
            }
        }

        return ans;
    }
};