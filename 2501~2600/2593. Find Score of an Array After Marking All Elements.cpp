class Solution {
public:
    long long findScore(vector<int>& nums) {
        int len = nums.size();
        vector<pair<int, int> > srt(len);
        long long ans = 0;
        bool mark[100000] = {};
        for(int i = 0; i < len; i++)
            srt[i] = make_pair(nums[i], i);
        sort(srt.begin(), srt.end());
        for(auto &i : srt){
            if(!mark[i.second]){
                mark[i.second] = true;
                ans += i.first;
                if(i.second - 1 >= 0) mark[i.second - 1] = true;
                if(i.second + 1 < len) mark[i.second + 1] = true;
            }
        }
        return ans;
    }
};
