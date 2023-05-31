class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> entryLog;
    unordered_map<string, unordered_map<string, pair<int, int>>> timeLog;
    
    UndergroundSystem() {
        entryLog.clear();
        timeLog.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        entryLog[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = entryLog[id];
        entryLog.erase(id);
        auto [cnt, totTime] = timeLog[startStation][stationName];
        int curTime = t - startTime;
        timeLog[startStation][stationName] = {cnt + 1, totTime + curTime};
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto [cnt, totTime] = timeLog[startStation][endStation];
        return 1.0 * totTime / cnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */