class Solution {
public:
    int compress(vector<char>& chars) {
        int curr = chars[0];
        int streak = 0;
        int i = 0;
        for (auto& ch : chars) {
            if (ch == curr) {
                streak++;
            } else {
                chars[i] = curr;
                i++;
                if (streak > 1) {
                    string s = to_string(streak);
                    for (auto c : s) {
                        chars[i] = c;
                        i++;
                    }
                }
                streak = 1;
                curr = ch;
            }
        }
        chars[i] = curr;
        i++;
        if (streak > 1) {
            string s = to_string(streak);
            for (auto c : s) {
                chars[i] = c;
                i++;
            }
        }
        return i;
    }
};