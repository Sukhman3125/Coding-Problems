class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int,int>> subs(26,{-1,-1});
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(subs[ch-'a'].first == -1){
                subs[ch-'a'].first = i;
            }
            subs[ch-'a'].second = i;
        }

        for(int i=0;i<26;i++){
            auto& [_i,_j] = subs[i];
            if(_i==-1) continue;
            while(1){
                bool changed = false;
                for(int k=_i;k<=_j;k++){
                    auto [newS, newE] = subs[s[k]-'a'];
                    if(newS < _i) {
                        changed = true;
                        _i = newS;
                    }
                    if(newE > _j){
                        changed = true;
                        _j = newE;
                    }
                }
                if(!changed) break;
            }
        }
        vector<pair<int,int>> _;
        for(auto [i,j]:subs){
            if(i==-1) continue;
            _.push_back({i,j});
        }
        subs = _;
        sort(subs.begin(), subs.end(),[](const auto& a, const auto& b){
            auto& [i1,j1] = a;
            auto& [i2,j2] = b;
            return j1-i1+1 < j2-i2+1;
        });
        vector<pair<int,int>> ans;
        for(auto [i,j]:subs){
            bool overlapped = false;
            for(auto [i1,j1]:ans){
                if(
                    (i<=i1 && j>=i1) ||
                    (j>=j1 && i<=j1)    
                ) {
                    overlapped = true;
                    break;
                }
            }
            if(!overlapped) ans.push_back({i,j});
        }
        vector<string> res;
        for(auto [i,j]: ans){
            res.push_back(s.substr(i, j-i+1));
        }
        return res;
    }
};