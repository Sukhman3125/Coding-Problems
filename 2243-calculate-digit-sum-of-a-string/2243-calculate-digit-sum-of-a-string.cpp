class Solution {
private:
    void reduce(string& s, int k){
        int n = s.size();
        int currSum = 0;
        string res;
        for(int i=0;i<n;i++){
            currSum += s[i] - '0';
            if((i+1)%k == 0){
                res += to_string(currSum);
                currSum = 0;
            }
        }
        s = res;
        if(n%k == 0)
            return;
        s += to_string(currSum);
    }
public:
    string digitSum(string& s, int k) {
        while(s.size() > k){
            reduce(s, k);
        }
        return s;
    }
};