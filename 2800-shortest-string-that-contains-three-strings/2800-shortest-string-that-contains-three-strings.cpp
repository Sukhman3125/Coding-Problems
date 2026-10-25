class Solution {
private:
    string merge(string a, string b) {
        if (a.find(b) != string::npos) return a;
        if (b.find(a) != string::npos) return b;

        int n = min(a.size(), b.size());

        for (int len = n; len > 0; len--) {
            if (a.substr(a.size() - len) == b.substr(0, len))
                return a + b.substr(len);
        }

        return a + b;
    }

    string tryPerm(string a, string b, string c) {
        return merge(merge(a, b), c);
    }

public:
    string minimumString(string a, string b, string c) {
        vector<string> v = {
            tryPerm(a, b, c),
            tryPerm(a, c, b),
            tryPerm(b, a, c),
            tryPerm(b, c, a),
            tryPerm(c, a, b),
            tryPerm(c, b, a)
        };

        string ans = v[0];

        for (auto& s : v) {
            if (s.size() < ans.size() ||
                (s.size() == ans.size() && s < ans)) {
                ans = s;
            }
        }

        return ans;
    }
};