class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string ans;
        unsigned int n = num;
        while(n){
            int val = n%16;
            char c = val<=9?val+'0':val-10+'a';
            ans += c;
            n/=16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};