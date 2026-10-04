class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int EC) {
        
        int maxi = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        vector<bool> ans(n, false);
        for(int i = 0; i<n; i++)
        {
            int curr = candies[i] + EC;
            if(curr >= maxi)
                ans[i] = true;
        }

        return ans;
    }
};