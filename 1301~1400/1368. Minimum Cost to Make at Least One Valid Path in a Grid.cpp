class Solution {
public:
    int minCost(vector<vector<int>>& grid) { 
        int m = grid.size(), n = grid[0].size(), x, y, currentCost, nx, ny, extraCost, i;
        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // right, left, down, up
        vector<vector<int> > cost(m, vector<int>(n, 10001));
        deque<pair<int, int> > dq; // BFS queue, pair -> (x, y, current_cost)

        dq.emplace_front(0, 0);
        cost[0][0] = 0;

        while(!dq.empty()){
            x = dq.front().first;
            y = dq.front().second;
            dq.pop_front();
            currentCost = cost[x][y];

            for(i = 0; i < 4; ++i){
                nx = x + directions[i][0];
                ny = y + directions[i][1];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    extraCost = !(grid[x][y] == i + 1);

                    if(currentCost + extraCost < cost[nx][ny]){
                        cost[nx][ny] = currentCost + extraCost;
                        if (extraCost == 0)
                            dq.emplace_front(nx, ny);
                        else
                            dq.emplace_back(nx, ny);
                    }
                }
            }
        }
        return cost[m - 1][n - 1];
    }
};
