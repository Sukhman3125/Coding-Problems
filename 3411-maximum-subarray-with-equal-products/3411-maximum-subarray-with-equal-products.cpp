class Solution {
public:
    int maxLength(vector<int>& nums) {
        // lcm -> [max(arr), product(arr)]
        // gcd -> [1, min(arr)]
        // for n==2, lcm*gcd == prod always
        // for n>2, lcm*gcd == prod only when all are pairwise coprime
        int ans = 2, n = nums.size();
        int primes[4] = {2, 3, 5, 7};
        int primeCnt[4] = {0, 0, 0, 0};
        int i = 0, j = 0;
        while (j < n) {
            for (int pf1 = 0; pf1 < 4; pf1++) {
                if (nums[j] % primes[pf1] == 0)
                    primeCnt[pf1]++;
                while (primeCnt[pf1] > 1) {
                    for (int pf2 = 0; pf2 < 4; pf2++) {
                        if (nums[i] % primes[pf2] == 0)
                            primeCnt[pf2]--;
                    }
                    i++;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};