class Solution {
public:
    string customSortString(string order, string s) {
        
        int arr[26] = {0};
        int n = s.length();
        for(char ch: s)
            arr[ch - 'a']++;
        
        s = "";
        for(char ch: order)
        {
            for(int i = 0; i<26; i++)
            {
                if(arr[ch-'a'] > 0)
                {
                    s += ch;
                    arr[ch-'a']--;
                }
            }
        }

        for(int i = 0; i<26; i++)
        {
           while(arr[i] > 0)
            {
                s += (i + 'a');
                arr[i]--;
            } 
        }

        
        return s;
    }
};