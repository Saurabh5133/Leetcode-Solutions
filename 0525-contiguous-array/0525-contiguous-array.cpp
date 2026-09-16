class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int> mp; //sum, first_index

        mp[0] = -1;
        int sum = 0;
        int ans = 0;

        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
                sum--;
            else
                sum++;

            if(mp.find(sum) != mp.end())
            {
                int len = i - mp[sum];
                ans = max(len, ans);
            }
            else
                mp[sum] = i;
        }

        return ans;
    }
};