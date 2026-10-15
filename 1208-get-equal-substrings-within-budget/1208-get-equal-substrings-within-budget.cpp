class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.length();
        int i = 0;
        int j = 0;

        int cost = 0;
        int ans = 0;

        while(j<n)
        {
            char a = s[j];
            char b = t[j];

            cost += abs(s[j]-t[j]);

            if(cost > maxCost)
            {
                while(cost > maxCost)
                {
                    cost -= abs(s[i]-t[i]);
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;

    }
};