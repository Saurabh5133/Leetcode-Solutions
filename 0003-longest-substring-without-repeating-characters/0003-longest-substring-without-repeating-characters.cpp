class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i = 0, j = 0;

        map<char,int> freq;

        int ans = 0;

        while(j < s.length())
        {
            freq[s[j]]++;

            if(freq[s[j]] > 1)
            {
                while(freq[s[j]] > 1)
                {
                    freq[s[i]]-- ;
                    i++;
                }
            }

            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};