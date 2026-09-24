class Solution {
private:
    int d(int x){
        int a = 0;
        while(x){
            a += (x)%10;
            x/=10;
        }
        return a;
    }

public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(d(nums[i])==i)return i;
        }
        return -1;
    }
};