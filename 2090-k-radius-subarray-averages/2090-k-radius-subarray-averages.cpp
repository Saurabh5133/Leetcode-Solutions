class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);

        int window = 2*k+1;
        if(window>n)
            return ans;

        vector<long long> prefixSum(n,0);

        prefixSum[0] = nums[0];
        for(int i = 1; i<n; i++)
            prefixSum[i] =prefixSum[i-1] + nums[i];

        for(int mid = k; mid<n-k; mid++)
        {
            int left = mid-k;
            int right = mid+k;

            long long sum = prefixSum[right];
            if(left > 0)
                sum -= prefixSum[left-1];

            ans[mid] = sum/window;
        }

        return ans;
    }
};