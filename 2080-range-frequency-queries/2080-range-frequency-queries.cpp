class RangeFreqQuery {
    using ump = unordered_map<int, int>;

private:
    vector<ump> segTree;
    int n;

    ump add(const ump& a, const ump& b) {
        ump ans;
        for (auto [k, v] : a) {
            ans[k] += v;
        }
        for (auto [k, v] : b) {
            ans[k] += v;
        }
        return ans;
    }

    void buildSegTree(const vector<int>& arr, int i = 0, int l = 0,
                      int r = -1) {
        if (r == -1) {
            r = n - 1;
            segTree.resize(4 * n);
        }
        if (l == r) {
            segTree[i][arr[l]]++;
            return;
        }
        int m = l + (r - l) / 2;
        buildSegTree(arr, 2 * i + 1, l, m);
        buildSegTree(arr, 2 * i + 2, m + 1, r);
        segTree[i] = add(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

public:
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        buildSegTree(arr);
    }

    int query(const int& left, const int& right, const int& value, int l = 0,
              int r = -1, int i = 0) {
       if (r == -1)
            r = n - 1;
        if (r < left || l > right)
            return 0;
        if (l >= left && r <= right)
            return segTree[i][value];
        int m = l + (r - l) / 2;
        return query(left, right, value, l, m, 2*i+1)
            + query(left, right, value, m+1, r, 2*i+2);
    } 
};