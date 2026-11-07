class Solution {
    using p = pair<int, int>;

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<p, vector<p>, greater<p>> freeServers; // weight, index
        int m = servers.size(), n = tasks.size();

        for (int i = 0; i < m; i++)
            freeServers.push({servers[i], i});

        priority_queue<p, vector<p>, greater<p>> busyServers; // free time, index
        queue<int> pendingTasks;

        vector<int> ans;
        long long time = 0;
        int i = 0;

        while (!pendingTasks.empty() || i < n) {
            while (i < n && i <= time) {
                pendingTasks.push(i);
                i++;
            }
            while (!busyServers.empty() && busyServers.top().first <= time) {
                int idx = busyServers.top().second;
                busyServers.pop();
                freeServers.push({servers[idx], idx});
            }
            while (!pendingTasks.empty() && !freeServers.empty()) {
                int task = pendingTasks.front();
                pendingTasks.pop();

                int idx = freeServers.top().second;
                freeServers.pop();

                ans.push_back(idx);
                busyServers.push({time + tasks[task], idx});
            }
            if (!pendingTasks.empty() && freeServers.empty())
                time = busyServers.top().first;
            else
                time++;
        }
        return ans;
    }
};