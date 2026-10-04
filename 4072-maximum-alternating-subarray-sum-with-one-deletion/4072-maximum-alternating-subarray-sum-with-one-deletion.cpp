class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const long long NEG = LLONG_MIN / 4;

        long long noPlus = NEG;
        long long noMinus = NEG;

        long long delPlus = NEG;
        long long delMinus = NEG;

        long long ans = NEG;

        for (long long x : nums) {

            long long nNoPlus = NEG;
            long long nNoMinus = NEG;
            long long nDelPlus = NEG;
            long long nDelMinus = NEG;

            nNoPlus = x;

            if (noPlus != NEG)
                nNoMinus = max(nNoMinus, noPlus - x);

            if (noMinus != NEG)
                nNoPlus = max(nNoPlus, noMinus + x);


            if (noPlus != NEG)
                nDelPlus = max(nDelPlus, noPlus);

            if (noMinus != NEG)
                nDelMinus = max(nDelMinus, noMinus);


            if (delPlus != NEG)
                nDelMinus = max(nDelMinus, delPlus - x);

            if (delMinus != NEG)
                nDelPlus = max(nDelPlus, delMinus + x);


            noPlus = nNoPlus;
            noMinus = nNoMinus;
            delPlus = nDelPlus;
            delMinus = nDelMinus;

            ans = max({
                ans,
                noPlus,
                noMinus,
                delPlus,
                delMinus
            });
        }

        return ans;
    }
};