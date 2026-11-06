class Solution {
private:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if(a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }

public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), comp);

        int m = queries.size();

        vector<vector<int>> sortedQueries(m, {0, 0});
        for(int i = 0; i < m; i++)
            sortedQueries[i] = {i, queries[i]};

        sort(sortedQueries.begin(), sortedQueries.end(), comp);

        vector<int> freq(n + 1, 0);
        vector<int> ans(m);

        int l = 0, r = 0;
        int active = 0;

        for(auto& q : sortedQueries) {
            int time = q[1];

            while(r < logs.size() && logs[r][1] <= time) {
                int server = logs[r][0];
                if(freq[server]++ == 0)
                    active++;
                r++;
            }

            while(l < r && logs[l][1] < time - x) {
                int server = logs[l][0];
                if(--freq[server] == 0)
                    active--;
                l++;
            }

            ans[q[0]] = n - active;
        }

        return ans;
    }
};