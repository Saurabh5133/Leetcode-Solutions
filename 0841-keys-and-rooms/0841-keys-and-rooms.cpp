class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<bool> visited(n,false);

        queue<int> q;

        q.push(0);

        while(!q.empty())
        {
            int room = q.front();
            q.pop();
            visited[room] = true;
            for(int nbr: rooms[room])
            {
                if(visited[nbr] == false)
                {
                    q.push(nbr);
                    // visited[nbr] == true;
                }
            }
        }

        for(bool v: visited)
        {
            if(v == false)  
                return false;
        }

        return true;
    }
};