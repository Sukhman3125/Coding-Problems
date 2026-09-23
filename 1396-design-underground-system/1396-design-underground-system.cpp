class UndergroundSystem {
private:
    unordered_map<string, pair<long long, int>> avg; 
    // first is sum of all samples and second is number of samples. first/second gives average
    unordered_map<int, pair<string, int>> checkInData;
    // first is station name and second is the time

    string mergeKeys(const string& a, const string& b){
        return a + "_" + b;
    }
public:
    void checkIn(int id, const string& startStation, int t) {
        checkInData[id] = {startStation, t};
    }
    
    void checkOut(int id, const string& endStation, int t) {
        const auto& [startStation, t0] = checkInData[id];
        auto& [total, samples] = avg[mergeKeys(startStation, endStation)];
        total += t-t0;
        samples++;
    }
    
    double getAverageTime(const string& startStation, const string& endStation) {
        const auto& [total, samples] = avg[mergeKeys(startStation, endStation)];
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