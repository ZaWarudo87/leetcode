class Solution {
public:
    void dfs(int r, int c, int &ans, vector<vector<int> > &grid){
        int m = grid.size(), n = grid[0].size();
        if(r < 0 || r >= m || c < 0 || c >= n || !grid[r][c])
            return;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        ans += grid[r][c];
        grid[r][c] = 0;
        for(int i = 0; i < 4; ++i)
            dfs(r + dir[i][0], c + dir[i][1], ans, grid);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0, i, j, temp, r, c;
        for(i = 0; i < m; ++i){
            for(j = 0; j < n; ++j){
                if(grid[i][j]){
                    temp = 0;
                    dfs(i, j, temp, grid);
                    ans = max(ans, temp);
                }
            }
        }

        return ans;
    }
};
