class Solution {
public:
    int maxLength(vector<int>& nums) {
        // lcm -> [max(arr), product(arr)]
        // gcd -> [1, min(arr)]
        // for n==2, lcm*gcd == prod always
        // for n>2, lcm*gcd == prod only when all are pairwise coprime
        int ans = 2, n = nums.size();
        pair<int, int> primes[4] = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};    // prime number, its count
        int i = 0, j = 0;
        while (j < n) {
            for (int pf1 = 0; pf1 < 4; pf1++) {
                if (nums[j] % primes[pf1].first == 0)
                    primes[pf1].second++;
                while (primes[pf1].second > 1) {
                    for (int pf2 = 0; pf2 < 4; pf2++) {
                        if (nums[i] % primes[pf2].first == 0)
                            primes[pf2].second--;
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