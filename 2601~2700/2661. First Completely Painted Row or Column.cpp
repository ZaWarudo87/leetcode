class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int i, j, m = mat.size(), n = mat[0].size(), len = m * n;
        vector<pair<int, int> > dis(len + 1);
        vector<int> line[2];
        line[0].resize(m);
        line[1].resize(n);

        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
                dis[mat[i][j]] = make_pair(i, j);
        
        for(i = 0; i < len; ++i)
            if(++line[0][dis[arr[i]].first] >= n || ++line[1][dis[arr[i]].second] >= m)
                return i;
        return m * n - 1;
    }
};
