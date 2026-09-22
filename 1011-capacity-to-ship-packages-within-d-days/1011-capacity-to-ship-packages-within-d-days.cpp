class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        int minCapacity = *max_element(weights.begin(), weights.end());
        int maxCapacity = 0;
        for(int i : weights)
            maxCapacity += i;

        int i = minCapacity;
        int j = maxCapacity;

        while(i<=j)
        {
            int currCapacity = i+(j-i)/2;
            
            int n_days = 1;
            int sum = 0;
            int k = 0;
            for(int k = 0; k<n; k++)
            {
                // int currCapacity = j+(j-1)/2;
                if(sum + weights[k] > currCapacity)
                {
                    n_days++;
                    sum = weights[k];
                }
                else
                {
                    sum += weights[k];
                }
            }

            if(n_days <= days)
            {
                j = currCapacity-1;
            }
            else
            {
                i = currCapacity+1;
            }
        }

        return i;

    }
};