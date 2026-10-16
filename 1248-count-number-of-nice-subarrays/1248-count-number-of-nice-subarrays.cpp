class Solution {
public:

    int atMostK(vector<int>& nums, int k)
    {
        int n = nums.size();
        int i = 0; int j = 0;
        int sum = 0;
        int ans = 0;

        while(j<n)
        {
            if(nums[j]%2 != 0)
                sum += 1;

            while(sum > k)
            {
                if(nums[i]%2 != 0)
                {
                    sum -= 1;
                }
                i++;
            }
            ans += j-i+1;

            j++;

        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return atMostK(nums, k) - atMostK(nums, k-1);
    }
};