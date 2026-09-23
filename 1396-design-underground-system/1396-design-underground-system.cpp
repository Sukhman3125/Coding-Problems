class UndergroundSystem {
private:
    unordered_map<string, pair<long long, int>> avg; 
    // first is sum of all samples and second is number of samples. first/second gives average
    unordered_map<int, pair<string, int>> checkInData;
    // first is station name and second is the time

    string hash(string& a, string& b){
        return a + "_" + b;
    }
public:
    void checkIn(int id, string startStation, int t) {
        checkInData[id] = {startStation, t};
    }
    
    void checkOut(int id, string endStation, int t) {
        auto& [startStation, t0] = checkInData[id];
        auto& [total, samples] = avg[hash(startStation, endStation)];
        total += t-t0;
        samples++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto& [total, samples] = avg[hash(startStation, endStation)];
        return total/(1.0 * samples);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */