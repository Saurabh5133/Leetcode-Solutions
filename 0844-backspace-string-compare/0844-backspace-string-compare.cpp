class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int n = s.length();

        string s1 = "";
        string s2 = "";

        for(int i = 0; i<n; i++)
        {
            if(s[i] == '#')
            {
                if(!s1.empty())
                    s1.pop_back();
            }
            else
            {
                s1 += s[i];
            }
        }
        
        int m = t.length();
        for(int i = 0; i<m; i++)
        {
            if(t[i] == '#')
            {
                if(!s2.empty())
                    s2.pop_back();
            }
            else
            {
                s2 += t[i];
            }
        }
        return s1 == s2;
    }
};