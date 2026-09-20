class Solution {
private:
    int pack(int a, int b) { 
        return (a << 14) | b;
    }
    pair<int, int> unpack(int x) { 
        return {
            x >> 14, 
            x & ((1 << 14) - 1)
        };
    }

public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        for(auto& h:health){
            h = (h+power-1)/power;
        }
        for(int i=0;i<n;i++){
            damage[i] = pack(damage[i], health[i]);
        }
        sort(damage.begin(), damage.end(), [&](const int& a, const int& b){
            auto [d1, h1] = unpack(a);
            auto [d2, h2] = unpack(b);
            return h1 * d2 < h2 * d1;
        });
        long long ans = 0;
        long long t = 0;
        for(auto it:damage){
            auto [d, h] = unpack(it);
            t += h;
            ans += t * d;
        }
        return ans;
    }
};