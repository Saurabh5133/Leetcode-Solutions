class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        unordered_map<int,int> mp;
        int n = barcodes.size();
        if(n == 1 || n == 2)
            return barcodes;

        for(int i = 0; i<n; i++)
            mp[barcodes[i]]++;

        priority_queue<pair<int,int>> pq;

        for(auto &it: mp)
        {
            pq.push({it.second, it.first});
        }

        vector<int> ans(n);
        int index = 0;

        while(!pq.empty())
        {
            auto [freq, value] = pq.top();
            pq.pop();

            while(freq > 0)
            {
                ans[index] = value;
                index += 2;
                freq--;

                if(index >= n)
                    index = 1;
            }
        }
        return ans;
    }
};