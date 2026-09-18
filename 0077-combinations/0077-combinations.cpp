class Solution {
public:

    vector<vector<int>> result;

    void makeSet(int n, int k, int start, vector<int> &ans)
    {
        if(ans.size() == k)
        {
            result.push_back(ans);
            return;
        }

        for(int i = start; i<=n; i++)
        {
            ans.push_back(i);
            makeSet(n, k, i+1, ans);
            ans.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        
        result.clear();
       vector<int> ans;
       makeSet(n, k, 1, ans);
       return result;
    }
};