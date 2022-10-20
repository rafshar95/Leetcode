class Solution {
public:


    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<std::vector<int>> adj(n), weight(n), distance(k + 2, std::vector<int> (n, -1));
        for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back(flights[i][1]);
            weight[flights[i][0]].push_back(flights[i][2]);
        }
        distance[0][src] = 0;
        for(int i = 0; i <= k; i++)
            for(int j = 0; j < n; j++)
                if(distance[i][j] != -1)
                    for(int l = 0; l < adj[j].size(); l++){
                        int neighbor = adj[j][l];
                        if(distance[i + 1][neighbor] == -1 || distance[i + 1][neighbor] > distance[i][j] + weight[j][l]){
                            distance[i + 1][neighbor] = distance[i][j] + weight[j][l];
                        }
                    }

        int cheapest_price = -1;
        for(int i = 0; i <= k + 1; i++)
            if(cheapest_price == -1 || (cheapest_price > distance[i][dst] && distance[i][dst] != -1))
               cheapest_price = distance[i][dst];
        return cheapest_price;

    }
};
