class Solution {
public:
    string maxValue(string n, int x) {
        string ans;
        bool done = false;
        if (n[0] == '-') {
            ans = "-";
            for (int i = 1; i < n.size(); i++) {
                int digit = n[i] - '0';
                if (digit > x && !done) {
                    ans += to_string(x);
                    done = true;
                }
                ans += n[i];
            }
            if (!done) ans += to_string(x);
            return ans;
        }

        for (char c : n) {
            int digit = c - '0';
            if (digit < x && !done) {
                ans += to_string(x);
                done = true;
            }
            ans += c;
        }

        if (!done) ans += to_string(x);

        return ans;
    }
};