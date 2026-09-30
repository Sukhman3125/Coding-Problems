class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int lMax = 0, rMax = 0;
        int ans = 0;

        while (l <= r) {
            if (h[l] <= h[r]) {
                if (h[l] >= lMax)
                    lMax = h[l];
                else
                    ans += lMax - h[l];

                l++;
            } else {
                if (h[r] >= rMax)
                    rMax = h[r];
                else
                    ans += rMax - h[r];

                r--;
            }
        }

        return ans;
    }
};