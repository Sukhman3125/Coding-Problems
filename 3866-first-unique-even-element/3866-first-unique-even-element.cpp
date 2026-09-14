class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> f;
        for(auto it:nums) f[it]++;
        for(auto it:nums){
            if(f[it]==1 && it%2==0) return it;
        }
        return -1;
    }
};