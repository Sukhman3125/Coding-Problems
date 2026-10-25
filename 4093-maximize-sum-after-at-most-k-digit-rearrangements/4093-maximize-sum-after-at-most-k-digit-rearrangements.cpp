class Solution {
private:
    int bestPerm(int x) {
        string s = to_string(x);
        sort(s.begin(), s.end(), greater<char>());
        return stoi(s);
    }

public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<pair<int, int>> v;

        for (int x : nums) {
            v.push_back({bestPerm(x) - x, x});
        }

        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i < k)
                ans += v[i].first + v[i].second;
            else
                ans += v[i].second;
        }

        return ans;
    }
};