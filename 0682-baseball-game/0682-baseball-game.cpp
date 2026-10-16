class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> st;
        int n = operations.size();

        for(auto c: operations)
        {
            if(c == "+")
            {
                int a = st.top();
                st.pop(); 
                int b = st.top();
                st.pop();
                st.push(b);
                st.push(a);
                st.push(a+b);
            }
            else if(c == "D")
            {
                int a = st.top();
                // st.pop();
                st.push(a+a);
            }
            else if(c == "C")
            {
                int a = st.top();
                st.pop();
            }
            else
                st.push(stoi(c));
        }

        int sum = 0;

        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};