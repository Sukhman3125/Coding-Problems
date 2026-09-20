class Solution {
public:
    bool canTransform(string start, string result) {
        int _R=0, _L=0;
        int n = start.size();
        for(int i=0;i<n;i++){
            if(start[i]=='R') _R++;
            if(result[i]=='R'){
                if(_L==1 || _R==0) return false;
                _R--;
            }
            if(result[i]=='L') _L++;
            if(start[i]=='L'){
                if(_R==1 || _L==0) return false;
                _L--;
            }
        }
        return _R==0 && _L==0;
    }
};