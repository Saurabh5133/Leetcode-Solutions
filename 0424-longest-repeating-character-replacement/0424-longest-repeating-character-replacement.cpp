class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int count[26] ={0};
        int left = 0, right = 0;

        int maxFreq = 0;
        int maxLen = 0;

        for(right; right<s.length(); right++)
        {
            count[s[right] - 'A']++;

            maxFreq = max(maxFreq, count[s[right]-'A']);

            int winLen = right - left + 1;

            int replacement = winLen - maxFreq;

            if(replacement > k)
            {
                count[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right-left+1);
        }

        return maxLen;

    }
};