class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<char> st;
        int count = 0;

        for(int i = 0; i<s.length(); i++)
        {
            
            if(s[i] == ')')
            {
                count--;

                if(count<0)
                {
                    count = 0;
                    continue;
                }
                else
                    st.push(s[i]);
            }
            else
            {
                if(s[i] == '(')
                    count++;

                st.push(s[i]);
            }
        }

        string ans = "";
        while(!st.empty())
        {
            char ch = st.top();
            st.pop();

            if(ch == '(' && count>0)
            {
                count--;
                continue;
            }
            ans += ch; 
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};