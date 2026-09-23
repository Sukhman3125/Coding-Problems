class Solution {
public:
    int maxJump(vector<int>& stones) {
        int maxi = stones[1] - stones[0];
        for(int i=2; i < stones.size(); i++){
            maxi = max(maxi, stones[i] - stones[i-2]);
        }
        return maxi;
    }
};