class Solution {
private:
    struct cmp {
        bool operator()(const auto& a, const auto& b) const {
            if(a[1] != b[1]) return a[1] > b[1];
            return a[2] > b[2];
        }
    };

public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) { 
            return a[0] < b[0]; 
        });
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        long long currTime = 0;
        int i=0;
        vector<int> ans;
        while(i<n || !pq.empty()){
            while(i<n && tasks[i][0] <= currTime){
                pq.push(tasks[i]);
                i++;
            }
            if(pq.empty()){
                currTime = tasks[i][0];
                continue;
            }
            currTime += pq.top()[1];
            ans.push_back(pq.top()[2]);
            pq.pop();
        }
        return ans;
    }
};