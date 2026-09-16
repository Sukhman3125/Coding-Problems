class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        bool isWord = false;
        for(auto it:s){
            if(it==' '){
                if(isWord) cnt++;
                isWord = false;
            }else{
                isWord = true;
            }
        }
        if(isWord) cnt++;
        return cnt;
    }
};