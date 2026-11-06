class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
        int i = 1;

        int ans = 0;

        while(i<n-1)
        {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
            {
                int left = i;
                int right = i;

                while(left > 0 && arr[left-1] < arr[left])
                    left--;

                while(right < n-1 && arr[right] > arr[right+1])
                    right++;

                i = right;
                ans = max(ans, right-left+1);
            }
            else
            {
                i++;
            }
        }

        return ans;
    }
};