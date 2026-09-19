class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int i = 0;
        int j = 0;
        stack<int> st;
        int n = pushed.size();

        while(i<n)
        {
            int num = pushed[i];
            st.push(num);

            if(st.top() == popped[j])
            {
                while(!st.empty() && j<n && st.top() == popped[j])
                {
                    st.pop();
                    j++;
                }
            }
            
            i++;
        }

        // while(j<n)
        // {
        //     if(st.top() != popped[j])
        //         return false;

        //     st.pop();
        //     j++;
        // }

        return st.empty();
    }
};