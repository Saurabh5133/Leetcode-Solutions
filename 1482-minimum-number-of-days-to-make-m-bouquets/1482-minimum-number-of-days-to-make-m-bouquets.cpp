class Solution {
public:

    bool makeBouquets(vector<int>& bloomDay, int m, int k, int days)
    {
        int n = bloomDay.size();
        int total = 0;
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(bloomDay[i] <= days)
            {
                count++;
            }
            else
            {
                count = 0;
            }

            if(count == k)
            {
                total++;
                count = 0;
            }

            if(total == m)
                return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        // if(m*k > n)
        //     return -1;

        // sort(bloomDay.begin(), bloomDay.end());

        int i = *min_element(bloomDay.begin(), bloomDay.end());
        int j = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(i<=j)
        {
            int mid = i + (j-i)/2;

            if(makeBouquets(bloomDay, m, k, mid))
            {
                ans = mid;
                j = mid-1;
            }
            else
            {
                i = mid+1;
            }
        }

        return ans;
    }
};