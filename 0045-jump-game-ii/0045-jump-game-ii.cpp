class Solution {
public:

    vector<int> dp;

    int build(vector<int> &nums, int i)
    {
        int n = nums.size();
        if( i >= n-1)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int mini = INT_MAX;

        for(int j = 1; j<=nums[i] && i+j < n; j++)
        {
            int ans = build(nums, i+j);

            if(ans != INT_MAX)
                mini = min(mini, ans+1);
            //  mini = min(mini, 1 + build(nums, i + j));
        }

        return dp[i] = mini;
    }

    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        dp.resize(n,-1);
        return build(nums, 0);
    }
};