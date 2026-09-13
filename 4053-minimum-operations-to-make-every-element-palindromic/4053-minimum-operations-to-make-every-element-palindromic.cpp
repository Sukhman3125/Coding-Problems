class Solution {
    using ll = long long;

    static void build(vector<ll>& even, vector<ll>& odd) {
        even = {0, 2, 4, 6, 8};
        odd = {1,3,5,7,9};
        for (ll i = 1; i <= 99999; i++) {
            string s = to_string(i), t = s;
            reverse(t.begin(), t.end());

            ll p1 = stoll(s + t);
            if (p1 % 2 == 0) even.push_back(p1);
            else odd.push_back(p1);

            for (int j = 0; j <= 9; j++) {
                ll p2 = stoll(s + to_string(j) + t);
                if (p2 % 2 == 0) even.push_back(p2);
                else odd.push_back(p2);
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
    }

    static vector<ll>& getEven() {
        static vector<ll> even, odd;
        static bool built = false;
        if (!built) { build(even, odd); built = true; }
        return even;
    }

    static vector<ll>& getOdd() {
        static vector<ll> even, odd;
        static bool built = false;
        if (!built) { build(even, odd); built = true; }
        return odd;
    }

public:
    long long minOperations(vector<int>& nums) {
        vector<ll>& even = getEven();
        vector<ll>& odd = getOdd();

        ll ans = 0;
        for (ll x : nums) {
            vector<ll>& v = (x & 1) ? odd : even;
            auto it = lower_bound(v.begin(), v.end(), x);
            ll best = LLONG_MAX;
            if (it != v.end()) best = min(best, *it - x);
            if (it != v.begin()) {
                --it;
                best = min(best, x - *it);
            }
            ans += best / 2;
        }
        return ans;
    }
};