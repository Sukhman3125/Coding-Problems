class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        s = s+s;
        int currScore = 0;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) currScore++;
        }
        int cnt = 0;
        if(currScore==k) cnt++;
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i]) currScore--;
            if(s[i+n-2] == s[i+n-1]) currScore++;
            if(currScore==k) cnt++;
        }
        return cnt;
    }
};