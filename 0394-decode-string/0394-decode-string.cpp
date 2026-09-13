class Solution {
public:
    string decodeString(string s) {
        stack<string> stck;
        stack<int> stck1;
        string curr = "";
        int n = 0;
        for(auto ch:s){
            if(ch<='9' && ch>='0') n = n*10+(ch-'0');
            else if(ch=='['){
                stck1.push(n);
                stck.push(curr);
                n = 0;
                curr = "";
            }else if(ch==']'){
                string temp = curr;
                curr = stck.top();
                stck.pop();
                int repeat = stck1.top();
                stck1.pop();
                while(repeat){
                    curr+=temp;
                    repeat--;
                }
            }else{
                curr+=ch;
            }
        }
        return curr;
    }
};