class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size(), ans = 0;
        unordered_map<string, int> f;

        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            string curr = "";

            for (int j = i; j < min(n, i + maxSize); j++) {
                st.insert(s[j]);

                if (st.size() > maxLetters)
                    break;

                curr += s[j];

                if (curr.size() >= minSize)
                    ans = max(ans, ++f[curr]);
            }
        }

        return ans;
    }
};