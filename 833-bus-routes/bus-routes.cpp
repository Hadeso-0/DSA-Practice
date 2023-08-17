class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        vector<vector<int>> busesAtStation(1e6+1);
        
		//  Precompute which buses pass through a given station
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                busesAtStation[routes[i][j]].push_back(i);
            }
        }
        
        queue<int> busQ;
		
		// Push all the buses that pass through source into the queue
        for(int bus : busesAtStation[source]) busQ.push(bus);
        
        vector<int> visitedBuses(1e6+1,0),visitedStations(1e6+1,0);
        visitedStations[source]=1;
        int cnt=0;
        
        while(busQ.size()>0){
            int sz=busQ.size();
            cnt++;
            while(sz--){
                int bus=busQ.front();
                busQ.pop();
                
                for(int station : routes[bus]){
                    if(station==target){
                        return cnt;
                    }
                    if(visitedStations[station]==0){
                        for(int bus: busesAtStation[station]){
                            if(visitedBuses[bus]==0){
                                busQ.push(bus);
                                visitedBuses[bus]=1;
                            }
                        }
                        visitedStations[station]=1;
                    }
                }
            }
        }
        
        return -1;
    }
};