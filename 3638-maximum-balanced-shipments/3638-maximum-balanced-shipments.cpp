class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int ans = 0, maxi = 0;
        for (int w : weight) {
            maxi = max(maxi, w);
            if (w < maxi) {
                ans++;
                maxi = 0;
            }
        }
        return ans;
    }
};