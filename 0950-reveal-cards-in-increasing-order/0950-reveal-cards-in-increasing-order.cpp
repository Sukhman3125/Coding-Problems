class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> q;
        int n = deck.size();
        for(int i=n-1; i>=0; i--){
            q.push_front(deck[i]);
            if(i==0) continue;
            int x = q.back();
            q.pop_back();
            q.push_front(x);
        }
        vector<int> ans;
        ans.reserve(n);
        for(auto it:q){
            ans.push_back(it);
        }
        return ans;
    }
};

// 2 3 5 7 11 13 17
// 17
// 13 17
// 17 13
// 11 17 13
// 13 11 17
// 7 13 11 17
// 17 7 13 11
// 5 17 7 13 11
// 11 5 17 7 13
// 3 11 5 17 7 13
// 13 3 11 5 17 7
// 2 13 3 11 5 17 7