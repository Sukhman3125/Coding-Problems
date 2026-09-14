class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = a;
        int cnt = 1;
        int n = b.size();

        while(s.size() < n){
            s += a;
            cnt++;
        }

        if(s.contains(b)){
            return cnt;
        }

        s += a;
        cnt++;

        if(s.contains(b)){
            return cnt;
        }

        return -1;
    }
};