class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int n = source.size();
        if(n==1)
            return source[0] == target[0];
        long long sum1 = accumulate(source.begin(), source.end(), 1LL*0);
        long long sum2 = accumulate(target.begin(), target.end(), 1LL*0);
        return sum1 == sum2;
    }
};