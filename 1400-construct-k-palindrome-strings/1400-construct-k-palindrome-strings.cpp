class Solution {
public:
    bool canConstruct(string s, int k) {
        
        int n = s.length();
        if(n<k)
            return false;

        if(n == k)
            return true;


        unordered_map<char, int> mp;

        int arr[26] = {0};

        for(char ch: s)
            arr[ch-'a']++;

        int oddCount = 0;
        for(int i = 0; i<26; i++)
        {
            if(arr[i]%2 != 0)
            {
                oddCount++;

                if(oddCount > k)
                    return false;
            }
        }
        return true;   
    }
};