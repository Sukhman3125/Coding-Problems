class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        string c1, c2;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) {
                if (c1 == "")
                    continue;
                ans.push_back({c1, c2});
                c1 = "", c2 = "";
                continue;
            }
            c1 += s1[i], c2 += s2[i];
        }
        if (c1 != "")
            ans.push_back({c1, c2});
        return ans;
    }
};