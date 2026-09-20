class Solution {
private:
    static inline string v = "aeiouAEIOU";
    static bool isVowel(char c){
        return v.contains(c);
    }
public:
    bool halvesAreAlike(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(!isVowel(s[i])) continue;
            if(i<n/2) cnt++;
            else cnt--;
            if(cnt<0) return 0;
        }
        return cnt==0;
    }
};