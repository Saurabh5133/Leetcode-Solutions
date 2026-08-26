class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        int n = nums.size();

        while(n != 1)
        {
            vector<int> newNums;

            for(int i = 0; i<n/2; i++)
            {
                int a = nums[i*2];
                int b = nums[i*2+1];

                if(i%2 == 0)
                {
                    int c = min(a,b);
                    newNums.push_back(c);
                }
                else
                {
                    int c = max(a,b);
                    newNums.push_back(c);
                }
            }
            
            nums = newNums;
            n = newNums.size();

        }

        return nums[0];

    }
};