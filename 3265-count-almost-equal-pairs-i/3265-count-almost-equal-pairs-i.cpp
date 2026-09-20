class Solution {
private:
    bool almEql(int& x, int& y) {
        string a = to_string(min(x, y));
        string b = to_string(max(x, y));
        reverse(a.begin(), a.end());
        while (a.size() < b.size()) {
            a += '0';
        }
        reverse(a.begin(), a.end());
        pair<char, char> mismatch;
        bool mismatched = false;
        bool swapped = false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i])
                continue;
            if(!mismatched){
                mismatch = {a[i], b[i]};
                mismatched = true;
            }else if(!swapped){
                if(a[i] != mismatch.second || b[i] != mismatch.first) return false;
                swapped = true;
            }else{
                return false;
            }
        }
        return !mismatched || swapped;
    }

public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (almEql(nums[i], nums[j]))
                    cnt++;
            }
        }
        return cnt;
    }
};