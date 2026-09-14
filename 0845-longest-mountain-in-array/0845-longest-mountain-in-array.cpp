class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for (int i = 1; i < n - 1; i++) {
            if (!(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]))
                continue;
            int l = i - 1, r = i + 1;
            while (l >= 0 && arr[l] < arr[l + 1]) {
                l--;
            }
            while (r < n && arr[r] < arr[r - 1]) {
                r++;
            }
            l++, r--;
            i = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};