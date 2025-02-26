class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ma = 0, mi = 0, ans = 0;
        for(int &i : nums){
            ma = max(ma + i, i);
            mi = min(mi + i, i);
            ans = max(ans, max(ma, -mi));
        }
        return ans;
    }
};
