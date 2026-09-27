class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            bitset<501> present;
            bitset<501> pSum;
            for(int j=i;j<n;j++){
                int x = nums[j];
                if(pSum[x]) break;
                if((present & (present >> x)).any()) break;
                pSum |= (present << x);
                present[x] = 1;
                ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};