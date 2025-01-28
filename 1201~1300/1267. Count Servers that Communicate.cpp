class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j, ans = 0;
        vector<bool> ym(m), yn(n);
        vector<int> rc(m, -1), cr(n, -1);
        for(i = 0; i < m; ++i){
            for(j = 0; j < n; ++j){
                if(grid[i][j]){
                    if(ym[i] || yn[j]){
                        if(rc[i] != -1){
                            ++ans;
                            cr[rc[i]] = -1;
                            rc[i] = -1;
                        }
                        if(cr[j] != -1){
                            ++ans;
                            rc[cr[j]] = -1;
                            cr[j] = -1;
                        }
                        ++ans;
                    }else{
                        rc[i] = j;
                        cr[j] = i;
                    }
                    ym[i] = 1;
                    yn[j] = 1;
                }
            }
        }
        return ans;
    }
};
