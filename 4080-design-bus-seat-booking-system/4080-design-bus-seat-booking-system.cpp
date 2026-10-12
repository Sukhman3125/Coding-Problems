class BusBooking {
private:
    int n;
    vector<int> booked[4];
    int bookingCnt = 0;
    int currTime = 0;

    pair<int, int> parseSeat(string& seat){
        return {
            seat[0]-'A',
            stoi(seat.substr(1))
        };
    }
public:
    BusBooking(int n) {
        this->n = n;
        for(auto& v:booked){
            v.assign(n+1, 0);
        }
    }
    
    void toggle(string seat) {
        auto [col, row] = parseSeat(seat);
        if(booked[col][row]){
            currTime -= booked[col][row];
            booked[col][row] = 0;
            bookingCnt--;
            return;
        }
        int cost = 1;
        bookingCnt++;
        if(
            (col == 0 && booked[1][row]) ||
            (col == 3 && booked[2][row]) 
        ) cost += 2;
        booked[col][row] = cost;
        currTime += cost;
    }
    
    int getTotalTime() {
        return currTime;
    }
    
    int getMinTime() {
        return bookingCnt;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */