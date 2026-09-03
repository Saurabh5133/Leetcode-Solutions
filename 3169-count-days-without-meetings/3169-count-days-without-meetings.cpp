class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(), meetings.end());
        int n = meetings.size();

        int result = 0;
        int lastend = 0;

        for(int i = 0; i<n; i++)
        {
            if(meetings[i][0]> lastend)
                result += meetings[i][0]-lastend-1;

            lastend = max(lastend, meetings[i][1]);
        }

        if(meetings[n-1][1] < days)
        {
            result += days - lastend;
        }

        return result;
    }
};