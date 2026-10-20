class Solution {
private:
    int n;
    class SubArray {
    public:
        bool isRotSorted;
        int maxi, mini;

        SubArray(bool b, int maxi, int mini) {
            isRotSorted = b;
            this->maxi = maxi;
            this->mini = mini;
        }
    };

    SubArray evaluateSubarray(vector<int>& nums, int l, int r) {
        int pivots = 0;
        int maxi = nums[l], mini = nums[l];
        for(int i=l+1;i<=r;i++){
            if(nums[i] < nums[i-1]) pivots++;
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        bool isRotSorted = pivots <= 1;
        if(pivots == 1){
            isRotSorted = nums[r] <= nums[l];
        }
        // cout<<"range:"<<l<<" to "<<r<<" pivot:"<<pivots<<endl;
        return SubArray(isRotSorted, maxi, mini);
    }

    bool sortable(vector<int>& nums, int k) {
        int prevMax = INT_MIN;
        // cout<<k<<endl;
        for (int i = 0; i < n; i += k) {
            SubArray curr = evaluateSubarray(nums, i, i + k - 1);
            if (!curr.isRotSorted)
                return false;
            if (curr.mini < prevMax)
                return false;
            prevMax = curr.maxi;
        }
        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        n = nums.size();
        int ans = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i != 0)
                continue;
            if (sortable(nums, i))
                ans += i;
            if (i*i == n) continue;
            if (sortable(nums, n/i))
                ans += n/i;
        }
        return ans;
    }
};