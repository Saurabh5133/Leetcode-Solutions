class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        int n = people.size();
        int boatCount = 0;

        int i = 0; 
        int j = n-1;

        while(i<=j)
        {
            if(people[i] + people[j] <= limit)
            {
                boatCount++;
                i++;
                j--;
            }
            else
            {
                boatCount++;
                j--;
            }
        }
        return boatCount;
    }
};