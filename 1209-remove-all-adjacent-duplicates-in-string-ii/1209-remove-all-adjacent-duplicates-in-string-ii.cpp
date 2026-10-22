class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<int,int>> st;
        
        for(char ch: s)
        {
            if(st.empty())
                st.push({ch,1});
            else
            {
                char temp = st.top().first;
                if(temp == ch)
                {
                    int cCount = st.top().second + 1;
                    st.pop();

                    if(cCount == k)
                        continue;
                    else
                        st.push({ch, cCount});
                }
                else
                    st.push({ch,1});
            }
        }

        string ans = "";

        while(!st.empty())
        {
            char ch = st.top().first;
            int freq = st.top().second;
            st.pop();

            while(freq > 0)
            {
                ans += ch;
                freq--;
            }
        }

         reverse(ans.begin(), ans.end());

        return ans;
    }
};