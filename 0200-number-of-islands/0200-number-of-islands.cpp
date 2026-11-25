class Solution {
public:

    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};

        visited[r][c] = 1;

        for(int i = 0; i<4; i++)
        {
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == '1')
            {
                dfs(nr, nc, grid, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));
        int count = 0;

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(i,j,grid, visited);
                    count++;
                }
            }
        }

        return count++;
    }
};