class Solution {
private:
    static inline bool st[26];
    static void clear(){
        for(auto& it:st)
            it = false;
    }
public:
    int partitionString(string s) {
        clear();
        int ans = 1;
        for(auto it:s){
            if(st[it-'a']){
                clear();
                ans++;
            }
            st[it-'a'] = true;
        }
        return ans;
    }
};