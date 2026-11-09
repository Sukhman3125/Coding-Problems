class Solution {
private:
    using p = pair<int, int>;
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> avl;
        for (int i = 0; i < k; i++)
            avl.insert(i);
        priority_queue<p, vector<p>, greater<p>> pq;    // free time, serverId
        int n = arrival.size();
        vector<int> reqFreq(k, 0);
        int maxFreq = 0;
        for(int i=0; i<n; i++){
            while(!pq.empty() && pq.top().first <= arrival[i]){
                avl.insert(pq.top().second);
                pq.pop();
            }
            if(avl.empty())
                continue;
            auto it = avl.lower_bound(i%k);
            int server = *avl.begin();
            if(it != avl.end())
                server = *it;
            maxFreq = max(maxFreq, ++reqFreq[server]);
            pq.push({arrival[i] + load[i], server});
            avl.erase(server);
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(reqFreq[i] == maxFreq)
                ans.push_back(i);
        }
        return ans;
    }
};
