class Solution {
private:
    const string genes = "ACGT";
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> valids;
        for(auto it:bank) valids.insert(it);
        queue<string> q;
        unordered_set<string> vis;
        q.push(startGene);
        vis.insert(startGene);
        int mutations = 0;
        while(!q.empty()){
            queue<string> next;
            while(!q.empty()){
                string currGene = q.front();
                q.pop();
                if(currGene == endGene) return mutations;
                for(auto& it:currGene){
                    char orig = it;
                    for(auto g:genes){
                        if(g==orig) continue;
                        it = g;
                        if(vis.contains(currGene) || !valids.contains(currGene)) 
                            continue;
                        vis.insert(currGene);
                        next.push(currGene);
                    }
                    it = orig;
                }
            }
            mutations++;
            cout<<mutations<<endl;
            q = next;
        }
        return -1;
    }
};