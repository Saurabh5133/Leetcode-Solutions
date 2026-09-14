class Solution {
public:
    typedef pair<long long, int> P;
    int M = 1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,vector<pair<int,int>>> adj_list;

        for(auto &road: roads)
        {
            int u = road[0];
            int v = road[1];
            int time = road[2];

            adj_list[u].push_back({v,time});
            adj_list[v].push_back({u,time});
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<long long> result(n, LLONG_MAX);

        vector<int> pathCount(n,0);

        result[0] = 0;
        pathCount[0] = 1;

        pq.push({0,0}); // time,node

        while(!pq.empty())
        {
            int currNode = pq.top().second;
            long long time = pq.top().first;

            pq.pop();

            for(auto &it: adj_list[currNode])
            {
                int nbr = it.first;
                int nbrTime = it.second;

                if(time + nbrTime < result[nbr])
                {
                    result[nbr]  = time + nbrTime;
                    pq.push({result[nbr], nbr});

                    pathCount[nbr] = pathCount[currNode];
                }
                else if(time+nbrTime == result[nbr])
                {
                    pathCount[nbr] = (pathCount[nbr] + pathCount[currNode])%M;
                }
            }
        }

        return pathCount[n-1];

    }
};