class Solution {
public:
    int minOperations(string s) {
        int maxi = 0;
        for(auto it:s){
            maxi = max(
                maxi,
                (26 - (it-'a')) % 26
            );
        }
        return maxi;
    }
};
