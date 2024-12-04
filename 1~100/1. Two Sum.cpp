class Solution {
private:
    static bool comp(pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<pair<int, int> > srt(len);
        vector<int> fir(len), sec(len);
        for(int i = 0; i < len; i++){
            srt[i].first = nums[i];
            srt[i].second = i;
        }
        sort(srt.begin(), srt.end(), Solution::comp);
        for(int i = 0; i < len; i++){
            fir[i] = srt[i].first;
            sec[i] = srt[i].second;
        }

        vector<int>::iterator ans;
        for(vector<int>::iterator i = fir.begin(); i != fir.end(); i++){
            ans = lower_bound(i + 1, fir.end(), target - *i);
            if(ans != fir.end() && *ans == target - *i)
                return {sec[i - fir.begin()], sec[ans - fir.begin()]};
        }
        return {};
    }
};
