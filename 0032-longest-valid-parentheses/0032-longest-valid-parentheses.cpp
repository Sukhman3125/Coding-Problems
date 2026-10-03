class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0;
        int closed = 0;
        for(char& ch:s){
            if(ch=='(') open++;
            if(ch==')') closed++;
            if(closed>open){
                closed--;
                ch = '.';
            }
        }
        open = 0;
        closed = 0;
        for(char& ch:views::reverse(s)){
            if(ch=='(') open++;
            if(ch==')') closed++;
            if(open>closed){
                open--;
                ch = '.';
            }
        }
        
        int currLen = 0;
        int maxi = 0;
        for(auto ch:s){
            if(ch=='.') currLen = 0;
            else currLen++;
            maxi = max(currLen,maxi);
        }
        return maxi;
    }
};