class Solution {
public:
    int minRotations(string& s) {
        int ans = 0;
        char prev = '0';
        for(auto it:s){
            ans += min(
                (it-prev+10)%10,
                10 - ((it-prev+10)%10)   
            );
            prev = it;
        }
        return ans;
    }
};