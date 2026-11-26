class Solution {
public:
    int maxArea(vector<int>& height) {

        int maxArea = 0;

        int lp = 0; 
        int rp = height.size()-1;

        while(lp<rp)
        {
            int length = min(height[lp], height[rp]);
            int width = rp - lp;

            int area = length*width;
            maxArea = max(area, maxArea);

            if(height[lp] < height[rp])
            {
                lp++;
            }
            else
            {
                rp--;
            }
        }

        return maxArea;




        // int n = height.size();
        // int maxArea = 0;
        // int area = 0;

        // for(int i = 0; i<n; i++)
        // {
        //     for(int j = 0; j<n; j++)
        //     { 
        //         area = (abs(j-i))*(min(height[i],height[j]));
        //         maxArea = max(area, maxArea);
        //     }
            
        // }
        // return maxArea;
    }
};