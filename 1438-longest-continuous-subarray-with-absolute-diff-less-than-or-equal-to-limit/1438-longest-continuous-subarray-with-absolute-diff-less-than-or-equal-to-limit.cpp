class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int i = 0, ans = 0, n = nums.size();
        for (int j = 0; j < n; j++) {
            st.insert(nums[j]);
            while (*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[i]));
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};