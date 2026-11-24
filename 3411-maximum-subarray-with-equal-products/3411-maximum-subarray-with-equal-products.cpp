class Solution {
public:
    int maxLength(vector<int>& nums) {
        // lcm -> [max(arr), product(arr)]
        // gcd -> [1, min(arr)]
        // for n==2, lcm*gcd == prod always
        // for n>2, lcm*gcd == prod only when all are pairwise coprime
        int ans = 2, n = nums.size();
        int primes[4] = {2,3,5,7};
        unordered_map<int, int> primeCnt;
        int i=0, j=0;
        while(j<n){
            for(auto pf:primes){
                if(nums[j] % pf == 0)
                    primeCnt[pf]++;
                while(primeCnt[pf] > 1){
                    for(auto pf1:primes){
                        if(nums[i] % pf1 == 0)
                            primeCnt[pf1]--;
                    }
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};