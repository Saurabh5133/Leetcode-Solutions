class Solution {
public:

    bool isPossible(int f, vector<int> &position, int m)
    {
        int n = position.size();
        int prev = position[0];
        int count = 1;

        for(int i = 0; i<n; i++)
        {
            int curr = position[i];
            if(curr-prev >= f)
            {
                count++;
                prev = curr;
            }

            if(count == m)
                break;
        }
        return count == m;
    }

    int maxDistance(vector<int>& position, int m) {
        
        int n = position.size();
        sort(position.begin(), position.end());

        int minForce = 1;
        int maxForce = position[n-1] - position[0];

        int result = 0;

        while(minForce <= maxForce)
        {
            int mid = minForce + (maxForce-minForce)/2;

            if(isPossible(mid, position, m))
            {
                result = max(result, mid);
                minForce = mid + 1;
            }
            else
            {
                maxForce = mid - 1;
            }
        }

        return result;
    }
};