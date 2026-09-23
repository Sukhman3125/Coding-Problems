class Solution {
private:
    int toMin(string& t) {
        int h = 0, m = 0;
        bool onHour = true;
        for (auto it : t) {
            if (it == ':') {
                onHour = false;
                continue;
            }
            if (onHour) {
                h *= 10;
                h += it - '0';
            } else {
                m *= 10;
                m += it - '0';
            }
        }
        return h * 60 + m;
    }

public:
    vector<string> alertNames(vector<string>& keyName,
                              vector<string>& keyTime) {
        map<string, vector<int>> personData;
        int n = keyName.size();
        for (int i = 0; i < n; i++) {
            personData[keyName[i]].push_back(toMin(keyTime[i]));
        }
        vector<string> ans;
        for (auto& [p, v] : personData) {
            sort(v.begin(), v.end());
            for (int i = 2; i < v.size(); i++) {
                if (v[i] - v[i - 2] <= 60) {
                    ans.push_back(p);
                    break;
                }
            }
        }
        return ans;
    }
};