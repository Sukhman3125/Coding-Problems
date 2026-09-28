class Solution {
public:
    long long minimumSteps(string s) {
        int _0 = 0;
        long long ans = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0')
                _0++;
            else
                ans += _0;
        }
        return ans;
    }
};