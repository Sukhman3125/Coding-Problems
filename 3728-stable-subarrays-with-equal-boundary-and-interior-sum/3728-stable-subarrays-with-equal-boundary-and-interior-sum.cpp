class Solution {
    using ll = long long;

    string hash(ll a, ll b){
        return to_string(a) + "_" + to_string(b);
    }

public:
    ll countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();

        unordered_map<string, ll> mp;

        ll ans = 0;
        ll pref = 0;

        for (int r = 0; r < n; r++) {

            if (r >= 2) {
                ll prefixL = pref - capacity[r - 1];

                mp[hash(capacity[r - 2], prefixL)]++;
            }

            ll requiredPrefix = pref - capacity[r];

            ans += mp[hash(capacity[r], requiredPrefix)];

            pref += capacity[r];
        }

        return ans;
    }
};