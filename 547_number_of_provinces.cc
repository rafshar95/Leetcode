class Solution {
public:
    int Find(int v, std::vector<int>& root){
        if(root[v] == v)
            return v;
        return root[v] = Find(root[v], root);
    }
    void Union(int v, int u, std::vector<int>& root, std::vector<int>& rank){
        v = Find(v, root);
        u = Find(u, root);
        if(u == v)
            return;
        if(rank[u] > rank[v]){
            root[v] = u;
        }
        else if(rank[v] > rank[u]){
            root[u] = v;
        }
        else{
            root[u] = v;
            rank[v] = rank[v] + 1;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        std::vector<int> root(isConnected.size()), rank(isConnected.size());
        for(int i = 0; i < root.size(); i++)
            root[i] = i;
        for(int i = 0; i < isConnected.size(); i++)
            for(int j = i + 1; j < isConnected[i].size(); j++)
                if(isConnected[i][j])
                    Union(i, j, root, rank);
        int province_count = 0;
        for(int i = 0; i< root.size(); i++)
            if(root[i] == i)
                province_count++;
        return province_count;
    }
};
