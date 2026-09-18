class Solution {
private:
    int bin(vector<int>& v, int target, int l, int r) {
        int ans = l - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (v[m] < target) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int a = nums[i]; 
            for(int j=i+1;j<n;j++){
                int b = nums[j];
                int target = a+b;
                int firstValidIdx = bin(nums, target, j+1, n-1);
                ans += firstValidIdx - (j+1) + 1;
            }
        }
        return ans;
    }
};