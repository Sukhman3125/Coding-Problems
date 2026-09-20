class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        n = s.size();
        int m = -1;
        for(int i=n-2; i>=0; i--){
            if(s[i] < s[i+1]){
                m = i;
                break;
            }
        }
        if(m == -1) return -1;
        reverse(s.begin() + m + 1, s.end());
        auto tar = upper_bound(s.begin() + m + 1, s.end(), s[m]);
        swap(s[m], *tar);
        long long ans = stoll(s);
        return (ans > INT_MAX) ? -1: ans;
    }
};