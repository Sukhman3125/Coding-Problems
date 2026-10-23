class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long sum = 0;
        sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size();
        int i=0, j = n-1;
        for(int _ = 0; _<(n/4 + 1)/2; _++){
            sum += pizzas[j];
            i+=3;
            j--;
        }
        while(i<j){
            sum += pizzas[j-1];
            j-=2;
            i+=2;
        }
        return sum;
    }
};