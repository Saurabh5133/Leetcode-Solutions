class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int,int> mp;
        for(int i = 0; i<arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        unordered_map<int,int> mp2;

        for(auto it: mp)
        {
            if(mp2.find(it.second) == mp2.end())
                mp2[it.second] = 1;
            else
                return false;
        }

        return true;
    }
};