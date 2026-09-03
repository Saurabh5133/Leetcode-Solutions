class Solution {
public:

    vector<string> result;

    void helper(int open, int close, string &valid)
    {
        if(open == 0 && close == 0)
        {
            result.push_back(valid);
            return;
        }

        if(open>0)
        {
            valid.push_back('(');
            helper(open-1, close, valid);
            valid.pop_back();
        }

        if(close > open)
        {
            valid.push_back(')');
            helper(open, close-1, valid);
            valid.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string valid = "";
        helper(n,n,valid);
        return result;

    }
};