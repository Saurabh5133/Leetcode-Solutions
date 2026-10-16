class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int n = edges.size();
        unordered_map<int,vector<int>> mp;

        for(auto it : edges)
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }

        for(auto it: mp)
        {
            vector<int> v = it.second;
            if(v.size() == n)
                return it.first;
        }

        return -1;
    }
};