class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> srt(heights.begin(), heights.end());
        int ans = 0;
        sort(srt.begin(), srt.end());
        for(int i = 0, len = heights.size(); i < len; i++){
            if(heights[i] != srt[i])
                ++ans;
        }
        return ans;
    }
};
