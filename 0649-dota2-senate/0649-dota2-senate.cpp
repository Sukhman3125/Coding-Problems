class Solution {
private:
    int d_bans = 0;
    int r_bans = 0;
    int simulateRound(string& senate){
        for(auto& it:senate){
            if(it=='D'){
                if(d_bans) {
                    it = 'X';
                    d_bans--;
                }
                else r_bans++; 
            }else{
                if(r_bans) {
                    it = 'X';
                    r_bans--;
                }
                else d_bans++;
            }
        }
        string next = "";
        bool _D = false, _R = false;
        for(auto it:senate){
            if(it=='X') continue;
            next+=it;
            if(it=='R') _R = true;
            else _D = true;
        }
        senate = next;
        if(!_D) return 1;
        if(!_R) return -1;
        return 0;
    }
public:
    string predictPartyVictory(string senate) {
        while(1){
            int res = simulateRound(senate);
            if(res==0) continue;
            if(res==-1) return "Dire";
            if(res==1) return "Radiant";
        }
        return ""; // dead code
    }
};