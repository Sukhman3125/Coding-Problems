class Solution {
	private:
	vector<vector<int>> dp;
	int m,n;
	
	int lcs(string& s1, string& s2, int i=0, int j=0) {
		if(i==m || j==n) return 0;
		if(dp[i][j] != -1) return dp[i][j];
		if(s1[i] == s2[j]){
		    return dp[i][j] = 1+lcs(s1,s2,i+1,j+1);
		}
		return dp[i][j] = max(
		    lcs(s1,s2,i+1,j),
		    lcs(s1,s2,i,j+1)
	    );
	}
	
	public:
	int findMinCost(string &s1, string &s2, int cost1, int cost2) {
		m = s1.size(), n = s2.size();
		dp.assign(m, vector<int>(n, -1));
		int lcsSize = lcs(s1,s2);
		return cost1 * (m-lcsSize) + cost2*(n-lcsSize);
	}
};
