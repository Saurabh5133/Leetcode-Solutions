class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        
        if(n == 0)
            return true;
            
        int l = fb.size();
        
        for(int i = 0; i<l; i++)
        {
            bool left = (i == 0 || fb[i-1] == 0);
            bool right = (i == l-1 || fb[i+1] == 0);

            if(fb[i] == 0 && left && right)
            {
                fb[i] = 1;
                n--;
            }

            if(n == 0)
                return true;
        }

        return false;
    }
};