class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.length();
        unordered_map<char,int> freq;

        for(char ch: s)
        {
            freq[ch]++;
        }

        priority_queue<pair<int,char>> pq;

        for(auto it: freq)
            pq.push({it.second, it.first});

        string ans = "";
        while(!pq.empty())
        {
            auto it1 = pq.top();
            pq.pop();

            ans += it1.second;
            
            if(!pq.empty())
            {
                auto it2 = pq.top();
                pq.pop();
                ans += it2.second;

                if(it2.first > 1)
                    pq.push({it2.first-1, it2.second});
            }
            if(it1.first > 1)
                pq.push({it1.first-1, it1.second});

            if(pq.size() == 1 && pq.top().first > 1)
                return "";
            
        }
        return ans;
    }
};