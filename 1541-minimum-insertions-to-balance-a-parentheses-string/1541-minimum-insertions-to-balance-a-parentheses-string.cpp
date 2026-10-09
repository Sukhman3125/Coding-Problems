class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int stck = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '(') stck++;
            else if(s[i] == ')' && i!=n-1 && s[i+1] == ')'){  // "))"
                if(stck>0) stck--;
                else ans++;
                i++; 
            }else{                                            // ")"
                if(stck>0){
                    ans++;
                    stck--;
                }else{
                    ans += 2;
                }
            }
        }
        ans += stck*2;
        return ans;
    }
};