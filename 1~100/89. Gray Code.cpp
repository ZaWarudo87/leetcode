class Solution {
public:
    vector<int> grayCode(int n) {
        int i, j;
        long long l = 1 << n, now;
        bitset<16> nans;
        vector<int> ans(l);
        for(i = 0; i < l; i++){
            nans.reset();
            for(j = n - 1; j >= 0; j--){
                now = 1 << j;
                nans[n - 1 - j] = int((i + now) / (now << 1)) % 2;
            }
            ans[i] = nans.to_ullong();
        }
        return ans;
    }
};
