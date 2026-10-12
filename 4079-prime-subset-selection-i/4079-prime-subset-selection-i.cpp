class Solution {
private:
    static inline vector<bool> isPrime;
    static inline bool isInit = false;
    static inline vector<int> primes;
public:
    Solution() {
        if (isInit)
            return;
        isInit = true;
        isPrime.assign(1e6 + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= 1e6; i++) {
            for (int j = i * i; j <= 1e6; j += i) {
                isPrime[j] = false;
            }
        }
        for (int i = 0; i <= 1e6; i++) {
            if (isPrime[i])
                primes.push_back(i);
        }
    }

    vector<int> maxPrimes(int n, int s) {
        vector<int> ans;
        int sum = 0;
        for (auto it : primes) {
            if (it > n)
                return ans;
            if (sum + it > s)
                return ans;
            sum += it;
            ans.push_back(it);
        }
        return {}; // dead code
    }
};