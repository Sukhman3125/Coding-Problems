class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();
        vector<vector<int>> R(n+1);
        vector<int> f(26,-1), q;
        for(int m=n-1;m>=0;m--){
            int c = s[m] - 'a';
            if(f[c] >= 0) q.erase(find(q.begin(), q.end(), f[c]));
            f[c] = m;
            q.insert(q.begin(), m);
            for(int d = 0; d<q.size(); d++)
                R[m].push_back((d+1 < q.size()?q[d+1]:n) - q[d]);
        }
        long long ans = 0;
        vector<int> l(26,-1), p;
        for(int j=0;j<n;j++){
            int c = s[j]-'a';
            if(l[c]>=0) p.erase(find(p.begin(), p.end(), l[c]));
            l[c] = j;
            p.insert(p.begin(), j);
            for(int d=0;d<p.size() && d<R[j+1].size(); d++)
                ans += 1LL * (p[d]-(d+1<p.size() ? p[d+1]:-1))*R[j+1][d];
        }
        return ans;
    }
};