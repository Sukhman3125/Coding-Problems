class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i = 0;
        int n = asteroids.size();
        vector<int> ans;
        ans.reserve(n);
        while (i < n && asteroids[i] < 0) {
            ans.push_back(asteroids[i]);
            i++;
        }
        for (; i < n; i++) {
            int x = asteroids[i];
            while (!ans.empty() && ans.back() > 0 && x < 0) {
                if (ans.back() < -x) {
                    ans.pop_back();
                } else if (ans.back() == -x) {
                    ans.pop_back();
                    x = 0;
                    break;
                } else {
                    x = 0;
                    break;
                }
            }

            if (x != 0)
                ans.push_back(x);
        }
        return ans;
    }
};