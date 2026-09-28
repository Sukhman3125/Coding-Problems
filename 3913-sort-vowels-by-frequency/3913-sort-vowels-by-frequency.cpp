class Solution {
    using t = tuple<char, int, int>; // vow, freq, first_occ
private:
    static inline string VOW = "aeiou";

public:
    string sortVowels(string s) {
        vector<t> v;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (!VOW.contains(s[i]))
                continue;
            bool found = false;
            for (auto& [ch, f, _]: v) {
                if (ch == s[i]) {
                    f++;
                    found = true;
                }
            }
            if (!found)
                v.push_back({s[i], 1, i});
        }
        
        sort(v.begin(), v.end(), [](const t& a, const t& b) {
            const auto& [c1, f1, i1] = a;
            const auto& [c2, f2, i2] = b;
            if (f1 == f2)
                return i1 < i2;
            return f1 > f2;
        });
        int j = 0;
        for(auto& ch: s){
            if(!VOW.contains(ch))
                continue;
            auto& [c, f, _] = v[j];
            ch = c;
            f--;
            if(f==0)
                j++;
        }
        return s;
    }
};