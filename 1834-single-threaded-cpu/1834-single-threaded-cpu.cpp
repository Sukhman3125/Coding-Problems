class Solution {
using v = vector<int>;
private:
    struct comp{
        bool operator()(const v& a, const v& b) const {
            if(a[1]!=b[1]) return a[1]>b[1];
            return a[2]>b[2];
        }
    };
public:
    v getOrder(vector<v>& tasks) {
        int n=tasks.size();
        for(int i=0; i<n; i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end(), [](const v& a, const v& b){
            return a[0]<b[0];
        });
        priority_queue<v, vector<v>, comp> pq;
        long long time = 0;
        int i = 0;
        v ans;
        while(i<n || !pq.empty()){
            while(i<n && tasks[i][0] <= time){
                pq.push(tasks[i]);
                i++;
            }
            if(pq.empty()){
                time = tasks[i][0];
                continue;
            }
            ans.push_back(pq.top()[2]);
            time += pq.top()[1];
            pq.pop();
        }
        return ans;
    }
};