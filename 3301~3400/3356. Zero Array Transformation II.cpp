class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), len = queries.size(), k = 0, now = 0;
        vector<int> diff(n + 1);
        for(int i = 0; i < n; ++i){
            while(diff[i] + now < nums[i]){
                if(++k > len)
                    return -1;
                if(queries[k - 1][1] >= i){
                    diff[max(i, queries[k - 1][0])] += queries[k - 1][2];
                    diff[queries[k - 1][1] + 1] -= queries[k - 1][2];
                }
            }
            now += diff[i];
        }
        return k;
    }
};
