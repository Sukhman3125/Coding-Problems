class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        while(n){
            int mask = n&3;
            even += mask & 1;
            odd += (mask & 2)>>1;
            n >>= 2;
        }
        return {even, odd};
    }
};