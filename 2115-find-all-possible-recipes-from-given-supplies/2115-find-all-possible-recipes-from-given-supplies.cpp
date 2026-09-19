class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n = recipes.size();
        vector<bool> cooked(n, false);

        unordered_set<string> st(supplies.begin(), supplies.end());

        int count = n;

        while(count--)
        {
            for(int i = 0; i<n; i++)
            {
                if(cooked[i] == true)
                    continue;
                
                bool canBeCooked = true;

                for(int j = 0; j<ingredients[i].size(); j++)
                {
                    if(st.find(ingredients[i][j]) == st.end())
                    {
                        canBeCooked = false;
                        break;
                    }
                }

                if(canBeCooked)
                {
                    st.insert(recipes[i]);
                    cooked[i] = true;
                }
            }
        }

        vector<string> ans;

        for(int i = 0; i<n; i++)
        {
            if(cooked[i] == true)
            {
                ans.push_back(recipes[i]);
            }
        }

        return ans;
    }
};