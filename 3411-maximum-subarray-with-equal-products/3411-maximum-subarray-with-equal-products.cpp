class Solution {
private:
    static inline pair<int, int> primes[4] = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};    // prime number, its count
    void resolveNumber(int x, bool add){
        for(auto& [p,cnt]:primes){
            if(x%p == 0)
                cnt += add?1:-1;
        }
    }
    inline void addToWindow(int x){
        resolveNumber(x, true);
    }
    inline void removeFromWindow(int x){
        resolveNumber(x, false);
    }
    void cleanUp(){
        for(auto& [_, cnt]: primes)
            cnt = 0;
    }
public:
    int maxLength(vector<int>& nums) {
        // lcm -> [max(arr), product(arr)]
        // gcd -> [1, min(arr)]
        // for n==2, lcm*gcd == prod always
        // for n>2, lcm*gcd == prod only when all are pairwise coprime
        int ans = 2, n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            addToWindow(nums[j]);
            for(int p=0;p<4;p++){
                while(primes[p].second > 1){
                    removeFromWindow(nums[i]);
                    i++;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        cleanUp();
        return ans;
    }
};