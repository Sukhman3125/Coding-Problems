class Solution {
private:
    int sumOfDiv(int x){
        if(x==1)                    // 1 doesnt have 4 divisors
            return 0;
        int _x = sqrt(x);
        if(_x*_x == x)    // A perfect square has odd number of divisors
            return 0;
        int sum = 1 + x, cnt = 2;   // counting 1, x by default
        for(int i=2; i*i<x; i++){
            if(x%i==0){
                cnt+=2;
                sum += i;
                sum += x/i;
            }
            if(cnt > 4)
                return 0;
        }
        if(cnt!=4)
            return 0;
        return sum; 
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto it:nums)
            sum += sumOfDiv(it);
        return sum;
    }
};