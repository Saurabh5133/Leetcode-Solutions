class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b){ return a[1]>b[1]; });

        int n = boxTypes.size();
        int capacity = truckSize;
        int totalUnits = 0; 

        for(int i = 0; i<n; i++)
        {
            if(capacity > 0)
            {
                int no_of_boxes = boxTypes[i][0];

                if(no_of_boxes <= capacity)
                {
                    totalUnits += no_of_boxes*boxTypes[i][1];
                    capacity -= no_of_boxes;
                }
                else
                {
                    totalUnits += capacity*boxTypes[i][1];
                    break;
                }
            }
        }

        return totalUnits;
    }
};