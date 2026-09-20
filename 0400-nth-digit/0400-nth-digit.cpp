class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 1;
        long long cnt = 9;
        long long start = 1;

        while (n > digits * cnt) {
            n -= digits * cnt;
            digits++;
            cnt *= 10;
            start *= 10;
        }

        long long num = start + (n - 1) / digits;

        int index = (n - 1) % digits;

        return to_string(num)[index] - '0';
    }
};