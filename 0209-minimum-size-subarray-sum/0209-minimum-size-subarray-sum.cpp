class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int i = 0;
        int j  = 0;

        int len = 0;
        int maxLen = n;

        int sum = 0;

        for(int i = 0; i<n; i++)
            sum += nums[i];

        if(sum < target)
            return 0;

        sum = 0;

        while(j<n)
        {
            sum += nums[j];

            if(sum >= target)
            {
                len = j-i+1;
                maxLen = min(len,maxLen);

                while(sum >= target)
                {
                    sum-= nums[i];
                    i++;

                    if(sum >= target)
                    {
                        len = j-i+1;
                        maxLen = min(len,maxLen);
                    }
                }
            }
            j++;
        }

        return maxLen;
    }
};