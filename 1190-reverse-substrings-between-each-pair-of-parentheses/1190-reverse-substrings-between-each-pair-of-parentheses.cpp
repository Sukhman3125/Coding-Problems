class Solution {
private:
    void rev(string& s, int i, int j){
        while(i<j){
            swap(s[i],s[j]);
            i++,j--;
        }
    }
public:
    string reverseParentheses(string s) {
        stack<int> openParentheses;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(') openParentheses.push(i+1);
            else if(s[i] == ')'){
                rev(s,openParentheses.top(),i-1);
                openParentheses.pop();
            }
        }
        string ans;
        for(auto& it:s){
            if(it=='('||it==')') continue;
            ans.push_back(it);
        }
        return ans;
    }
};