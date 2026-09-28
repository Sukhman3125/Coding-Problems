class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int f[26] = {0};
        for(auto it:magazine) f[it-'a']++;
        for(auto it:ransomNote){
            if(!f[it-'a']) return false;
            f[it-'a']--;
        }
        return true;
    }
};