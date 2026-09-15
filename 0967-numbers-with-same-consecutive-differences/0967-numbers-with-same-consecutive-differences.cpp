class Solution {
private:
    vector<int> ans;
    int n,k;
    void recur(string s){
        if(s.size() == n){
            ans.push_back(stoi(s));
            return;
        }
        if(k==0){
            recur(s+s.back());
            return;
        }
        char curr = s.back()-k;
        if(curr>='0'){
            recur(s+curr);
        }
        curr = s.back()+k;
        if(curr<='9'){
            recur(s+curr);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        this->n = n, this->k = k;
        for(int d=1;d<=9;d++){
            recur(to_string(d));
        }
        return ans;
    }
};