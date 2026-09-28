class Solution {
private:
    int calcScore(vector<int>& v){
        int score = 0;
        int bonus = 0;
        for(auto it:v){
            if(!bonus){
                score += it;
            }else{
                score += 2*it;
                bonus--;
            }
            if(it==10) bonus = 2;
        }
        return score;
    }
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = calcScore(player1);
        int score2 = calcScore(player2);

        if(score1==score2) return 0;
        if(score1 > score2) return 1;
        return 2;
    }
};