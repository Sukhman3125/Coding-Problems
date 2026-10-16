class NumArray {
private:
    int n;
    vector<int> segTree;

    void buildSegTree(vector<int>& nums, int i = 0, int l = 0, int r = -1) {
        if (r == -1) {
            r = n - 1;
            segTree.resize(4 * n);
        }
        if (l == r) {
            segTree[i] = nums[l];
            return;
        }
        int m = l + (r - l) / 2;
        buildSegTree(nums, 2 * i + 1, l, m);
        buildSegTree(nums, 2 * i + 2, m + 1, r);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        buildSegTree(nums);
    }

    void update(int idx, int val, int i = 0, int l = 0, int r = -1) {
        if (r == -1)
            r = n - 1;
        if (l == r && l == idx) {
            segTree[i] = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) {
            update(idx, val, 2 * i + 1, l, m);
        } else {
            update(idx, val, 2 * i + 2, m + 1, r);
        }
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    int sumRange(int left, int right, int i = 0, int l = 0, int r = -1) {
        if (r == -1)
            r = n - 1;
        if (r < left || l > right)
            return 0;
        if (l >= left && r <= right)
            return segTree[i];
        int m = l + (r-l)/2;
        return sumRange(left, right, 2*i+1, l, m) + sumRange(left, right, 2*i+2, m+1, r);
    }
};