class Solution {
private:
    int setBits(int x){
        int res = 0;
        while(x){
            res += x & 1;
            x >>= 1;
        }
        return res;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int prevMax = 0, curMax = 0, curBits = -1;
        for(int x : nums){
            int b = setBits(x);
            if(b != curBits){
                prevMax = curMax;
                curMax = x;
                curBits = b;
            } else {
                curMax = max(curMax, x);
            }
            if(x < prevMax) return false;
        }
        return true;
    }
};