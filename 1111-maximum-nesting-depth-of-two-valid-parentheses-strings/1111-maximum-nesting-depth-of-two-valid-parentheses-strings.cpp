class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d1 = 0, d2 = 0;
        vector<int> ans;
        ans.reserve(seq.size());
        for(auto it:seq){
            if(it=='('){
                if(d1<=d2){
                    ans.push_back(0);
                    d1++;
                }else{ 
                    ans.push_back(1);
                    d2++;
                }
            }else{
                if(d1>=d2){
                    ans.push_back(0);
                    d1--;
                }else{
                    ans.push_back(1);
                    d2--;
                }
            }
        }
        return ans;
    }
};