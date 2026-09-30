class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        while(n){
            int mask = n&3;
            if(mask==1 || mask==3) even++;
            if(mask==2 || mask==3) odd++;
            n >>= 2;
        }
        return {even, odd};
    }
};