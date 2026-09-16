class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for (auto ch : num) {
            while (!s.empty() && k > 0 && s.back() > ch) {
                s.pop_back();
                k--;
            }
            s += ch;
        }
        while (k > 0) {
            s.pop_back();
            k--;
        }
        int i=0;
        int n = s.size();
        while(i<n){
            if(s[i] !='0') break;
            i++;
        }
        s = s.substr(i,n-i);
        if(s == "") return "0";
        return s;
    }
};