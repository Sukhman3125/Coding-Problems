class Solution {
using p = pair<int,int>;
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(auto it:s) freq[it-'a']++;
        priority_queue<p> pq;
        for(int i=0;i<26;i++) {
            if(freq[i] == 0) continue;
            pq.push({freq[i], i});
        }
        s = "";
        while(pq.size()>1){
            auto [f1,c1] = pq.top(); pq.pop();
            auto [f2,c2] = pq.top(); pq.pop();
            s += char(c1+'a');
            s += char(c2+'a');
            f1--, f2--;
            if(f1!=0) pq.push({f1,c1});
            if(f2!=0) pq.push({f2,c2});
        }
        if(pq.size() == 0) return s;
        auto [f,c] = pq.top();
        if(f==1) return s+char(c+'a');
        return "";
    }
};