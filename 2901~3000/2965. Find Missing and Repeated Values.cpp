class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2);
        bool check[2501] = {};
        for(vector<int> &i : grid){
            for(int &j : i){
                if(check[j])
                    ans[0] = j;
                else
                    check[j] = 1;
            }
        }
        for(int i = 1, len = grid.size(), n = len * len; i <= n; ++i){
            if(!check[i]){
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
};
