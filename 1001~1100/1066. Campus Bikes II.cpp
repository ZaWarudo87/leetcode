class Solution {
private:
    static int dis[10][10], premin[10];
    static int bst;
    
    static void ans(int pt, int bef, int &n, vector<bool> ok){
        if(pt >= n){
            Solution::bst = min(Solution::bst, bef);
            return;
        }else if(bef + premin[pt] >= Solution::bst)
            return;
        
        int now = 20000;
        for(int i = 0, len = ok.size(); i < len; i++){
            if(ok[i]) continue;
            ok[i] = 1;
            ans(pt + 1, bef + Solution::dis[pt][i], n, ok);
            ok[i] = 0;
        }
    }
    
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int i, j, n = workers.size(), m = bikes.size();
        Solution::bst = 20000;
        for(i = 0; i < n; i++){
            Solution::premin[i] = 20000;
            for(j = 0; j < m; j++){
                Solution::dis[i][j] = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                Solution::premin[i] = min(Solution::premin[i], Solution::dis[i][j]);
            }
        }
        
        for(i = n - 2; i >= 0; i--)
            premin[i] += premin[i + 1];
        
        vector<bool> ok(m);
        ans(0, 0, n, ok);
        return Solution::bst;
    }
};
int Solution::dis[10][10] = {}, Solution::premin[10] = {}, Solution::bst = 20000;
