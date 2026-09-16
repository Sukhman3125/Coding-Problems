class Solution {
private:
    int dSum(int x) {
        int ans = 0;
        while (x) {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }

public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>> numsWithIdx;
        for (int i = 0; i < nums.size(); i++) {
            numsWithIdx.push_back({nums[i], i});
        }
        sort(numsWithIdx.begin(), numsWithIdx.end(),
             [&](const auto& a, const auto& b) {
                 int x = dSum(a.first), y = dSum(b.first);
                 if (x == y)
                     return a.first < b.first;
                 return x < y;
             });

        int n = nums.size();
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || numsWithIdx[i].second == i)
                continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = numsWithIdx[j].second;
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};