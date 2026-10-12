class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a = 0;
        int b = 1;
        while(1){
            int c = a+b;
            if(a+b+c == n) return true;
            else if(a+b+c > n) return false;
            a = b;
            b = c;
        }
        return false; // dead code
    }
};