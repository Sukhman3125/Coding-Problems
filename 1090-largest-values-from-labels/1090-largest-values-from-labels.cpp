class Solution {
private:
    int pack(int a, int b){
        return (a<<16) | b;
    }
    pair<int,int> unpack(int x){
        return {
            x>>16,
            x & ((1<<16)-1)
        };
    }
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        for(int i=0;i<n;i++){
            values[i] = pack(values[i], labels[i]);
        }
        sort(values.begin(), values.end(), [&](const int& a, const int& b){
            return unpack(a).first>unpack(b).first;
        });
        unordered_map<int,int> usesOf;
        int totalUses = 0;
        int ans = 0;
        for(auto it:values){
            auto [v, l] = unpack(it);
            if(usesOf[l] == useLimit) continue;
            usesOf[l]++;
            ans += v;
            totalUses++;
            if(totalUses == numWanted) break;
        }
        return ans;
    }
};