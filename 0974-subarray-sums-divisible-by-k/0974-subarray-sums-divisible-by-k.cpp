class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp; // rem, count
        mp[0] = 1;

        int n = nums.size();

        vector<int> pSum(n,0);
        pSum[0] = nums[0];
        for(int i = 1; i<n; i++)
        {
            pSum[i] = pSum[i-1] + nums[i];
        }

        int count = 0;

        for(int i = 0; i<n; i++)
        {
            int rem = ((pSum[i]%k) + k)%k;

            if(mp.find(rem) != mp.end())
                count += mp[rem];
            
            mp[rem]++;
        }

        return count;
    }
};