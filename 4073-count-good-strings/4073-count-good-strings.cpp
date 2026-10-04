class Solution {
private:
    static inline int MOD = 1e9+7;
    pair<long long, long long> f(long long n) {
        if (n == 0)
            return {0, 1};

        auto [a, b] = f(n / 2);

        long long c = a * ((2 * b % MOD - a + MOD) % MOD) % MOD;
        long long d = (a * a + b * b)%MOD;   // F(2k + 1)

        if (n % 2 == 0)
            return {c, d};

        return {d, (c + d)%MOD};
    }

public:
    int countGoodStrings(long long n) { 
        return (f(n).first*2)%MOD; 
    }

    /*
    n=1 => 2
    1 a b

    n=2 => 2
    11 ab ba

    n=3 => 4
    111 aba bab
    3   aaa bbb

    n=4 => 6
    1111 aaaa bbbb
    13   abbb baaa
    31   baaa abbb

    n=5 => 10
    11111 ababa babab
    131   abbba baaab
    311   bbbab aaaba
    113   abaaa babbb
    5     aaaaa bbbbb

    n=6 => 16
    111111
    15
    51
    33
    1113
    1131
    1311
    3111
    */
};