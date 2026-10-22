class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int, int>> arr2;
        int n = nums1.size();
        arr2.reserve(n);

        for (int i = 0; i < n; i++)
            arr2.push_back({i, nums2[i]});

        sort(nums1.begin(), nums1.end());
        sort(arr2.begin(), arr2.end(),
             [](auto& a, auto& b) {
                 return a.second < b.second;
             });

        vector<int> ans(n);
        int i = 0, j = 0, r = n - 1;

        while (i < n) {
            if (nums1[i] > arr2[j].second) {
                ans[arr2[j].first] = nums1[i];
                i++;
                j++;
            } else {
                ans[arr2[r].first] = nums1[i];
                i++;
                r--;
            }
        }

        return ans;
    }
};