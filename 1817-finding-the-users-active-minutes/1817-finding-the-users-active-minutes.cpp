class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        vector<int> ans(k,0);
        unordered_map<int,unordered_set<int>> mpp;

        int n = logs.size();
        for(int i = 0; i<n; i++)
            mpp[logs[i][0]].insert(logs[i][1]);

        for(auto it: mpp)
        {
            auto uam = it.second.size();
            ans[uam-1]++;
        }

        return ans;

    }
};