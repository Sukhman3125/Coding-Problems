class EventManager {
using p = pair<int,int>;
using g = less<p>;
    priority_queue<p,vector<p>,g> pq;
    unordered_map<int,int> latestPriority;
public:
    EventManager(vector<vector<int>>& events) {
        for(auto& it:events){
            pq.push({it[1],-it[0]});
            latestPriority[it[0]] = it[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        pq.push({newPriority, -eventId});
        latestPriority[eventId] = newPriority;
    }
    
    int pollHighest() {
        while(!pq.empty()){
            int prior = pq.top().first;
            int curr = -pq.top().second;
            pq.pop();
            if(latestPriority[curr] == prior){
                latestPriority[curr] = 0;
                return curr;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */