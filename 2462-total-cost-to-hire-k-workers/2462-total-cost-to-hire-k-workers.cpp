class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n = costs.size();
        int i = 0;
        while(i<candidates && i<n){
            pq.push({costs[i], i});
            i++;
        }
        int j = n-1;
        while(j>=i && j>=n-candidates){
            pq.push({costs[j],j});
            j--;
        }
        int cnt = 0;
        long long ans = 0;
        while(cnt<k){
            ans += pq.top().first;
            int idx = pq.top().second;
            cnt++;
            pq.pop();
            if(i>j) continue;
            if(idx<i){
                pq.push({costs[i],i});
                i++;
            }
            else{
                pq.push({costs[j],j});
                j--;
            }
        }
        return ans;
    }
};