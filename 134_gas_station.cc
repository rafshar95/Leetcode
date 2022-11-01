class Solution {
public:
    struct station{
        int index;
        station* next;
        station* prev;
        station(): index(0), next(nullptr), prev(nullptr){}
        station(int index): index(index), next(nullptr), prev(nullptr){}
        station(int index, station* next, station* prev): index(index), next(next), prev(prev){}
    };
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int net_capacity = 0;
        for(int i = 0; i < gas.size(); i++){
            net_capacity += gas[i] - cost[i];
        }
        if(net_capacity < 0)
            return -1;
        std::set<std::pair<int,int>> gas_capacity;
        std::vector<station *> stations;
        station* station_prev, *new_station;
        station* head;
        for(int i = 0; i < cost.size(); i++){
            gas_capacity.insert(std::make_pair(gas[i] - cost[i], i));
            new_station = new station(i);
            if(i != 0){
                station_prev -> next = new_station;
                new_station  -> prev = station_prev;
            }
            else
                head = new_station;
            station_prev = new_station;
            stations.push_back(new_station);
        }
        new_station -> next = head;
        head -> prev = new_station;
        int starting_station = -1;
        while(gas_capacity.size()){
            starting_station = gas_capacity.begin() -> second;
            gas_capacity.erase(gas_capacity.begin());
            if(gas_capacity.size() == 0)
                break;
            station* next_station = stations[starting_station] -> next;
            station* prev_station = stations[starting_station] -> prev;
            gas_capacity.erase(std::make_pair(gas[prev_station -> index] - cost[prev_station -> index], prev_station -> index));
            gas[prev_station -> index] += gas[starting_station] - cost[starting_station];
            gas_capacity.insert(std::make_pair(gas[prev_station -> index] - cost[prev_station -> index], prev_station -> index));
            next_station -> prev = prev_station;
            prev_station -> next = next_station;
        }
        return starting_station;
    }
};
