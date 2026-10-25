class Solution {
public:

    int find(int x, vector<int>& parent)
    {
        if(parent[x] == x)  return x;
        return parent[x] = find(parent[x], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<int> parent(n+1);
        for(int i = 0; i<n+1; i++)
            parent[i] = i;

        for(auto &edge: edges)
        {
            int u = edge[0];
            int v = edge[1];

            int rootu = find(u, parent);
            int rootv = find(v, parent);

            if(rootu == rootv)
                return edge;
            
            parent[rootv] = rootu;
        }    

        return {};
    }
};