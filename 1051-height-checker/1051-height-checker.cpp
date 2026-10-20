class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        int freq[101] = {0};
        for(int h: heights)
            freq[h]++;

        int count = 0;
        int expectedHeight = 1;
        for(int i = 0; i<heights.size(); i++)
        {
            while(freq[expectedHeight] == 0)
                expectedHeight++;
            
            if(heights[i] != expectedHeight)
                count++;

            freq[expectedHeight]--;
        }

        return count;
    }
};