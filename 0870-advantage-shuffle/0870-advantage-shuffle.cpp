class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());

        vector<vector<int>> arr; // nums2[i], i

        for(int i = 0; i<n; i++)
        {
            arr.push_back({nums2[i], i});
        }

        sort(arr.begin(), arr.end());

        int i = 0; int j = n-1;
        int k = n-1;

        vector<int> ans(n);

        while(i<=j)
        {
            int curr = arr[k][0];
            int index = arr[k][1];
            if(nums1[j] > curr)
            {
                ans[index] = nums1[j];
                j--;
            }
            else
            {
                ans[index] = nums1[i];
                i++;
            }
            k--;
        }

        return ans;
    }
};