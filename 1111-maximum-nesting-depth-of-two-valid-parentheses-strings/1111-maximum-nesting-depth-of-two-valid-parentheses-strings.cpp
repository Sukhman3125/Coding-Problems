class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<char> stck1, stck2;
        int d1 = 0, d2 = 0;
        vector<int> ans;
        ans.reserve(seq.size());
        for(auto it:seq){
            if(it=='('){
                if(d1<=d2){
                    stck1.push(it);
                    ans.push_back(0);
                    d1++;
                }else{ 
                    stck2.push(it);
                    ans.push_back(1);
                    d2++;
                }
            }else{
                if(d1>=d2){
                    stck1.pop();
                    ans.push_back(0);
                    d1--;
                }else{
                    stck2.pop();
                    ans.push_back(1);
                    d2--;
                }
            }
        }
        return ans;
    }
};