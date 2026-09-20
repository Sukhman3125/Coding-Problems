class Solution {
private:
    static pair<string, string> split(const string& s) {
        int i = 0;
        while (s[i] != ' ')
            i++;
        return 
        {
            s.substr(0, i), 
            s.substr(i + 1)
        };
    }
    static bool comp(const string& a, const string& b) {
        const auto& [a_id, a_con] = split(a);
        const auto& [b_id, b_con] = split(b);
        if (!isdigit(a_con[0]) && !isdigit(b_con[0])) {
            if (a_con == b_con)
                return a_id < b_id;
            return a_con < b_con;
        } else if (isdigit(a_con[0]) && isdigit(b_con[0])) {
            return false; // stable sort will handle the ordering
        } else {
            return !isdigit(a_con[0]);
        }
    }

public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), comp);
        return logs;
    }
};