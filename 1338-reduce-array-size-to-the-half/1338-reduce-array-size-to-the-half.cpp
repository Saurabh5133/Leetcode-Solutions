class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int> mp;
        for(int num: arr)
            mp[num]++;

        vector<int> freq;

        for(auto it: mp)
        {
            freq.push_back(it.second);
        }

        sort(freq.rbegin(), freq.rend());

        int n = arr.size();
        int count = 0;
        int target = (n+1)/2;
        int removed = 0;

        for(int f: freq)
        {
            removed += f;
            count++;

            if(removed >= target)
                return count;
        }

        return count;
    }
};