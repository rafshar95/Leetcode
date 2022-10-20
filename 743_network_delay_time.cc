class Solution {
public:
    void dijkstra(int source, std::vector<std::vector<int> >& adj, std::vector<std::vector<int> >& weight, std::vector<int>& distance){
        std::set<std::pair<int, int>> candidates;
        cout<< "";
        candidates.insert({distance[source], source});
        while(!candidates.empty()){
            int candidate = candidates.begin() -> second;
            candidates.erase(candidates.begin());
            for(int i = 0; i < adj[candidate].size(); i++){
                int neighbor = adj[candidate][i];
                if(distance[neighbor] == -1 || distance[neighbor] > distance[candidate] + weight[candidate][i]){
                    candidates.erase({distance[neighbor], neighbor});
                    distance[neighbor] = distance[candidate] + weight[candidate][i];
                    candidates.insert({distance[neighbor], neighbor});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::vector<std::vector<int> > adj(n + 1), weight(n + 1);
        for(int i = 0; i < times.size(); i++){
            adj[times[i][0]].push_back(times[i][1]);
            weight[times[i][0]].push_back(times[i][2]);
        }
        std::vector<int> distance(n + 1, -1);
        distance[k] = 0;
        dijkstra(k, adj, weight, distance);
        int max_distance = 0;
        for(int i = 1; i <= n; i++){
            max_distance = std::max(max_distance, distance[i]);
            if(distance[i] == -1)
                return -1;
        }
        return max_distance;

    }
};
