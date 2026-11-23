class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        int n = s.length();
        if(n < 10)
            return {};
        unordered_map<string,int> freq;
        int i = 0;

        for(int j = 0; j<n-9; j++)
        {
            string temp = s.substr(j,10);
            freq[temp]++;
        }

        vector<string> ans;

        for(auto it: freq)
        {
            if(it.second > 1)
                ans.push_back(it.first);
        }

        return ans;
 
    }
};