class Solution {
public:
    int GetRoot(int v, std::vector<int>& parent){
        if(parent[v] == -1)
            return v;
        return (parent[v] = GetRoot(parent[v], parent));
    }
    void Merge(int vertex_v, int vertex_u, std::vector<int>& parent, std::vector<int>& rank){
        int root_v = GetRoot(vertex_v, parent);
        int root_u = GetRoot(vertex_u, parent);
        if(root_u == root_v)
            return;
        if(rank[root_v] < rank[root_u])
            std::swap(root_v, root_u);
        rank[root_v] += rank[root_u];
        parent[root_u] = root_v;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        std::vector<int> parent(n, -1);
        std::vector<int> rank(n, 1);
        for(int i = 0; i < edges.size(); i++)
            Merge(edges[i][0], edges[i][1], parent, rank);
        return GetRoot(source, parent) == GetRoot(destination, parent);
    }
};
