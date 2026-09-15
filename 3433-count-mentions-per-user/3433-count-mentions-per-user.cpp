class Solution {
private:
    vector<int> parseIDs(string s) {
        vector<int> ans;
        string curr;
        for (auto it : s) {
            if (it == 'i' || it == 'd')
                continue;
            if (it == ' ') {
                if (curr == "")
                    continue;
                ans.push_back(stoi(curr));
                curr = "";
            } else {
                curr += it;
            }
        }
        if (curr != "") {
            ans.push_back(stoi(curr));
        }
        return ans;
    }

public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            int ta = stoi(a[1]), tb = stoi(b[1]);
            if (ta != tb)
                return ta < tb;
            return a[0] == "OFFLINE" && b[0] == "MESSAGE";
        });
        vector<int> offline(n, -1); // if -1 -> online. else int is expiry time
        vector<int> ans(n,0);
        for (auto it : events) {
            string type = it[0];
            int time = stoi(it[1]);
            string user = it[2];
            if (type == "OFFLINE") {
                offline[stoi(user)] = time + 60;
                continue;
            }
            if (user == "ALL") {
                for (auto& it : ans)
                    it++;
            } else if (user == "HERE") {
                for (int i = 0; i < n; i++) {
                    if (offline[i] == -1) {
                        ans[i]++;
                        continue;
                    } else if(time >= offline[i]){
                        ans[i]++;
                        offline[i] = -1;
                        continue;
                    }
                }
            } else {
                auto users = parseIDs(user);
                for(auto& it:users){
                    ans[it]++;
                }
            }
        }
        return ans;
    }
};