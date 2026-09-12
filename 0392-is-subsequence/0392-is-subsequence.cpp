class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        int i = 0;
        for(auto it:t){
            if(it==s[i]) i++;
            if(i==s.size()) break;
        }
        if(i==s.size()) return true;
        return false;
    }
};