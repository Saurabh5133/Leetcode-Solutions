class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // int n = nums.size();
        // unordered_set<int> st;

        // for(int i = 0; i<n; i++)
        // {
        //     st.insert(nums[i]);
        // }

        // int lcs = 0;
        // for(auto it : st)
        // {
        //     if(st.find(it-1) != st.end())
        //         continue;
        //     else
        //     {
        //         int num = it;
        //         int curr_lcs = 1;
        //         while(st.find(num+1) != st.end())
        //         {
        //             curr_lcs++;
        //             num += 1;
        //         }
                
        //         lcs = max(lcs, curr_lcs);
        //     }

        // }
        // return lcs;

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for(int num : st)
        {
            if(!st.count(num-1))
            {
                int curr = num;
                int length = 1;

                while(st.count(curr+1))
                {
                    curr++;
                    length++;
                }

                longest = max(length, longest);
            }
        }

        return longest;
    }
};