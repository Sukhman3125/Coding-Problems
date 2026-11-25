class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int consecutive = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size(), ans = 0;
        for(int i=0; i<n;i++){
            pq.push(arr[i]);
            while(!pq.empty() && pq.top() == consecutive){
                pq.pop();
                consecutive++;
            }
            if(consecutive == i+1)
                ans++;
        }
        return ans;
    }
};