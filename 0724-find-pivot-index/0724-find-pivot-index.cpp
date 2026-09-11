class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> lSum(n);
        vector<int> rSum(n);

        lSum[0] = 0;
        rSum[n-1] = 0;
        
        int j = n-2;

        for(int i = 1; i<n; i++)
        {
            lSum[i] = nums[i-1] + lSum[i-1];
        }

        for(int i = n - 2; i >= 0; i--) {
            rSum[i] = nums[i + 1] + rSum[i + 1];
        }

        // if(rSum[0] == 0)
        // {
        //     return 0;
        // }

        // if(lSum[n-1] == rSum[n-1])
        //     return n-1;

        for(int i = 0; i<n; i++)
        {
            if(lSum[i] == rSum[i])
                return i;
        }

        return -1;
    }
};