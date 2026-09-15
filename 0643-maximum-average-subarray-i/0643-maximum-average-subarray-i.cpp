class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;

        double maxAvg = -DBL_MAX;
        double sum = 0;

        int n = nums.size();

        while(j < n)
        {
            sum += nums[j];

            if(j-i+1 == k)
            {
                double avg = sum/k;
                maxAvg = max(avg, maxAvg);

                sum -= nums[i];
                i++;
            }

            j++;

            
        }

        return maxAvg;
    }
};