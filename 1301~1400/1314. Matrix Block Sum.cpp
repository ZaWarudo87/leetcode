class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int i, j, m = mat.size(), n = mat[0].size(), a, b, c, d;
        vector<vector<int>> prefix(m, vector<int>(n)), ans(m, vector<int>(n));
        prefix[0][0] = mat[0][0];
        for(i = 1; i < n; ++i)
            prefix[0][i] = prefix[0][i - 1] + mat[0][i];
        for(i = 1; i < m; ++i){
            prefix[i][0] = prefix[i - 1][0] + mat[i][0];
            for(j = 1; j < n; j++)
                prefix[i][j] = mat[i][j] + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
        }
        
        for(i = 0; i < m; ++i){
            for(j = 0; j < n; ++j){
                a = (i + k < m ? i + k : m - 1);
                b = (j + k < n ? j + k : n - 1);
                c = i - k - 1;
                d = j - k - 1;
                ans[i][j] = prefix[a][b] - (d >= 0 ? prefix[a][d] : 0) - (c >= 0 ? prefix[c][b] : 0) + (c >= 0 && d >= 0 ? prefix[c][d] : 0);
            }
        }
        return ans;
    }
};
