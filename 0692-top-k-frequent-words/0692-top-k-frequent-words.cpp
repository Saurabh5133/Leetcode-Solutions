class Solution {
public:

    struct compare{

        bool operator()(const pair<int, string>& a,
                        const pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second; // larger word has higher priority
            return a.first > b.first;       // smaller frequency has higher priority
        }

    };


    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> mp;
        priority_queue<pair<int,string>, vector<pair<int,string>>, compare> pq;

        for(string word : words)
            mp[word]++;

        for(auto it : mp)
        {
            string key = it.first;
            int freq = it.second;

            pq.push({freq,key});

            if(pq.size() > k)
                pq.pop();
        }

        vector<string> ans;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            ans.push_back(it.second);
        }

        reverse(ans.begin(), ans.end());

        return ans;


    }
};