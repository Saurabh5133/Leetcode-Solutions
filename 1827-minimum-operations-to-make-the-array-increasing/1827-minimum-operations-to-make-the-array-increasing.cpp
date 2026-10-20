class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;

        for(int i = 0; i<n-1; i++)
        {
            int a = nums[i];
            int b = nums[i+1];

            if(b>a)
                continue;
            else
            {
                count += (a-b)+1;
                nums[i+1] = nums[i+1] + (a-b)+1;
            }
        }
        return count;
    }
};