class Solution {
private:
#pragma region seive
    static inline bool isPrime[1001];
    static inline bool isInit = false;
    static inline int primes[168];

public:
    Solution() {
        if (isInit)
            return;
        isInit = true;
        for (auto& it : isPrime)
            it = true;
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= 1000; i++) {
            for (int j = i * i; j <= 1000; j += i) {
                isPrime[j] = false;
            }
        }
        int j = 0;
        for (int i = 0; i <= 1000; i++) {
            if (!isPrime[i])
                continue;
            primes[j] = i;
            j++;
        }
    }
#pragma endregion

private:
    struct State {
        int cnt = 1e9;
        bitset<168> mask;
    };

    int m;
    vector<int> p;
    vector<vector<State>> memo;
    vector<vector<bool>> seen;

    State solve(int i, int s) {
        if (s == 0)
            return {0, bitset<168>()};

        if (i == m || s < 0)
            return {};

        if (seen[i][s])
            return memo[i][s];

        seen[i][s] = true;

        State skip = solve(i + 1, s);
        State take;

        if (p[i] <= s) {
            take = solve(i + 1, s - p[i]);

            if (take.cnt != 1e9) {
                take.cnt++;
                take.mask.set(i);
            }
        }

        State ans = skip;

        if (take.cnt < ans.cnt) {
            ans = take;
        } else if (take.cnt == ans.cnt && take.cnt != 1e9) {
            for (int j = 0; j < m; j++) {
                if (take.mask[j] != ans.mask[j]) {
                    if (take.mask[j])
                        ans = take;
                    break;
                }
            }
        }

        return memo[i][s] = ans;
    }

public:
    vector<int> maxPrimeSubset(int n, int s) {
        p.clear();

        for (int i = 0; i < 168; i++) {
            if (primes[i] == 0 || primes[i] > n)
                break;
            p.push_back(primes[i]);
        }

        m = p.size();

        if (m == 0 || s < 2)
            return {};

        memo.assign(m + 1, vector<State>(s + 1));
        seen.assign(m + 1, vector<bool>(s + 1, false));

        for (int sum = s; sum >= 2; sum--) {
            State result = solve(0, sum);

            if (result.cnt == 1e9)
                continue;

            vector<int> ans;
            for (int i = 0; i < m; i++) {
                if (result.mask[i])
                    ans.push_back(p[i]);
            }

            return ans;
        }

        return {};
    }
};