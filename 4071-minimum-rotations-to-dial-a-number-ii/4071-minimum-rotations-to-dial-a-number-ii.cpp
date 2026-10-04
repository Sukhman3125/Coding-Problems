class Solution {
public:
    int dist(int a, int b) {
        int d = abs(a - b);
        return min(d, 10 - d);
    }

    int minRotations(int n, string s) {
        vector<int> suff(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + dist(s[i] - '0', s[i + 1] - '0');
        }

        int ans = dist(0, s[0] - '0') + suff[0];

        for (int k = 0; k < n; k++) {

            int curr = 0;

            if (k == 0) {
                curr = dist(0, s[n - 1] - '0') + suff[0];
            } 
            else {
                curr = dist(0, s[0] - '0') + suff[0] - dist(s[k - 1] - '0', s[k] - '0');

                curr += dist(s[k - 1] - '0', s[n - 1] - '0');
            }

            ans = min(ans, curr);
        }

        return ans;
    }
};