class UndergroundSystem {
    map<int, pair<string,int>> ind_to_log;
    map<string, map<string, pair<int,double>>> stn_graph;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ind_to_log[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> log_ = ind_to_log[id];
        int time_taken = t - log_.second;
        string station_from = log_.first;
        // cout<<id<<"  "<<station_from<<" "<<stationName<<" "<<time_taken<<endl;
        if(stn_graph[station_from].find(stationName) == stn_graph[station_from].end()){
            stn_graph[station_from][stationName] = {1, time_taken};
        }
        else{
            pair<int, double> x = stn_graph[station_from][stationName];
            double time_upd = (((double)x.first*x.second) + time_taken)/((double)x.first+1.0);
            // cout<<id<<" "<<x.first<<" "<<x.second<<" -> ";
            stn_graph[station_from][stationName] = {x.first+1, time_upd};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        if(stn_graph[startStation].find(endStation) == stn_graph[startStation].end()){
            return -1.0;
        }
        return stn_graph[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */