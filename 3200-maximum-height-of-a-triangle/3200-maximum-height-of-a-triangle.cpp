class Solution {
private:
    int calc(int a, int b){
        // 1+3+5..n... = n*n
        // 2+4+6..n... = n*(n+1)
        int oddRows = sqrt(a);
        int evenRows = (sqrt(4*b + 1) - 1)/2;
        if(oddRows <= evenRows) return 2*oddRows;
        return 2*evenRows + 1;
    }
public:
    int maxHeightOfTriangle(int r, int b) {
        return max(calc(r,b), calc(b,r));
    }
};