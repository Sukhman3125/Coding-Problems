class Solution {
public:
    void helper(vector<string>& ans,int& n,string str, int size,int left){
        if(size == 2*n){
            if(left == size - left){
                cout<<"a";
                ans.push_back(str);
            }
            return;
        }
        helper(ans,n,str + "(",size+1,left+1);
        if(left > size - left){
            helper(ans,n,str + ")",size+1,left);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans,n,"",0,0);
        return ans;
    }
};