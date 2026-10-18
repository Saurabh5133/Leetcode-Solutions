class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int> freq(1001,0);
        for(int num: arr1)
        {
            freq[num]++;
        }

        int index = 0;

        for(int num: arr2)
        {
            while(freq[num]>0)
            {
                arr1[index++] = num;
                freq[num]--;
            }
        }

        for(int i = 0; i<freq.size(); i++)
        {
            while(freq[i] > 0)
            {
                arr1[index++] = i;
                freq[i]--;
            }
        }
        return arr1;
    }
};