class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        int curr = 1;
        bool flag = true;
        int i = 0;

        vector<string> ans;

        while(i<target.size() && curr <= n)
        {
            int num = target[i];

            ans.push_back("Push");

            if(num == curr)
            {
                i++;
            }
            else
                ans.push_back("Pop");

            curr++;
        }

        return ans;
    }

};