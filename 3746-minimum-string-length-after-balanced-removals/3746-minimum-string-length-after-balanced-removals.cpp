class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<char> stck;
        for(auto ch:s){
            if(!stck.empty() && stck.top() != ch) stck.pop();
            else stck.push(ch);
        }
        return stck.size();
    }
};