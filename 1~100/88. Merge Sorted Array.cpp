class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptm = 0, ptn = 0, pt = 0;
        vector<int> ans(m + n);
        while(pt < m + n){
            if(ptm >= m || ptn < n && nums2[ptn] < nums1[ptm])
                ans[pt++] = nums2[ptn++];
            else
                ans[pt++] = nums1[ptm++];
        }
        nums1 = ans;
    }
};
