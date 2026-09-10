class Solution {
public:

    void bfs(vector<vector<int>>& mat,queue<pair<int,int>> &q,  vector<vector<int>> &dis)
    {
        int n = mat.size();
        int m = mat[0].size();

        int X[4] = {0,-1,0,1};
        int Y[4] = {1,0,-1,0};

        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();

            for(int i = 0; i<4; i++)
            {
                int nx = x + X[i];
                int ny = y + Y[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && dis[nx][ny] == -1)
                {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push({nx,ny});
                }
                
            }
        }

    }


    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dis(n, vector<int>(m,-1));


        for(int i = 0; i<n; i++)
        {
            for(int  j = 0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                    dis[i][j] = 0;
                }
                
            }
        }

        bfs(mat, q, dis);

        return dis;

    }
};