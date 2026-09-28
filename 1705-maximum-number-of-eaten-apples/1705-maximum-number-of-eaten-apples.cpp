class Solution {
private:
    using p = pair<int,int>;
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<p, vector<p>, greater<p>> pq;
        int n = apples.size();
        int day = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            pq.push({days[i]+i, apples[i]});
            while(!pq.empty() && pq.top().first <= day){
                pq.pop();
            }
            if(!pq.empty()){
                ans++;
                auto [d, a] = pq.top(); 
                pq.pop();
                if(--a > 0)
                    pq.push({d,a});
            }
            day++;
        }
        while(!pq.empty()){
            while(!pq.empty() && pq.top().first <= day){
                pq.pop();
            }
            if(!pq.empty()){
                ans++;
                auto [d, a] = pq.top(); 
                pq.pop();
                if(--a > 0)
                    pq.push({d,a});
            }
            day++;
        }
        return ans;
    }
};