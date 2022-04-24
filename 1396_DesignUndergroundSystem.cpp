"""
An underground railway system is keeping track of customer travel times between different stations. They are using this data to calculate the average time it takes to travel from one station to another.

Implement the UndergroundSystem class:

    void checkIn(int id, string stationName, int t)
        A customer with a card ID equal to id, checks in at the station stationName at time t.
        A customer can only be checked into one place at a time.
    void checkOut(int id, string stationName, int t)
        A customer with a card ID equal to id, checks out from the station stationName at time t.
    double getAverageTime(string startStation, string endStation)
        Returns the average time it takes to travel from startStation to endStation.
        The average time is computed from all the previous traveling times from startStation to endStation that happened directly, meaning a check in at startStation followed by a check out from endStation.
        The time it takes to travel from startStation to endStation may be different from the time it takes to travel from endStation to startStation.
        There will be at least one customer that has traveled from startStation to endStation before getAverageTime is called.

You may assume all calls to the checkIn and checkOut methods are consistent. If a customer checks in at time t1 then checks out at time t2, then t1 < t2. All events happen in chronological order.
"""
class UndergroundSystem {
public:
    
    unordered_map<int, pair<string, int>> chkInMp; // Route -> {Total Time, Count}
    unordered_map<string, pair<int, int>> chkOutMp; // Uid -> {StationName, Time}
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        chkInMp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto &checkin = chkInMp[id];
        string route = checkin.first + "." + stationName;
        chkOutMp[route].first += t- checkin.second;
        chkOutMp[route].second +=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation+"."+endStation;
        auto &checkout = chkOutMp[route];
        return (double) checkout.first/checkout.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */