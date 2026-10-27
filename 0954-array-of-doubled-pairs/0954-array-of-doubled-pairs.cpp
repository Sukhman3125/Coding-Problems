class Solution {
private:
    struct absComp{
        bool operator()(const int& a, const int& b) const {
            if(abs(a) == abs(b))
                return a<b;
            return abs(a) < abs(b);
        }
    };
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int, absComp> freq;
        for(auto it:arr)
            freq[it]++;
        for(auto& [x, f]:freq){
            if(x==0){
                if(f%2 != 0)
                    return false;
                f=0;
                continue;
            }
            if(f==0)
                continue;
            if(freq[2*x]<f)
                return false;
            freq[2*x] -= f;
            f = 0;
        }
        return true;
    }
};

// a[1] = 2*a[0]
// a[3] = 2*a[2]
// a[5] = 2*a[4]