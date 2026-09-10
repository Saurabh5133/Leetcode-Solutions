class Solution {
public:

    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;

        int area = 1;

        area += dfs(i+1, j, grid);
        area += dfs(i-1, j, grid);
        area += dfs(i, j+1, grid);
        area += dfs(i, j-1, grid);

        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        // queue<pair<int,int>> q;

        int maxArea = 0;
        
        // int X[4] = {0,-1,0,1};
        // int Y[4] = {1,0,-1,0};

        // vector<vector<bool>> visited(n, vector<int>(m,false));

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = dfs(i,j,grid);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;   
    }
};