class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int backlog=0;
        for(auto it:data){
            if(backlog){
                if((it&(3<<6))!=(2<<6)) return false;
                backlog--;
                continue;
            }
            if((it&(1<<7))==0){}
            else if((it&(7<<5))==(6<<5))
                backlog=1;
            else if((it&(15<<4))==(14<<4))
                backlog=2;
            else if((it&(31<<3))==(30<<3))
                backlog=3;
            else return false;
        }
        if(backlog ) return false ;
        return true;
    }
};