class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int now = 0, ans = 0, st = 0, i = 0;
        endTime.insert(endTime.begin(), 0);
        startTime.push_back(eventTime);
        for(; i <= k; ++i)
            now += startTime[i] - endTime[i];
        ans = now;
        for(int len = startTime.size(); i < len; ++i){
            now = now + (startTime[i] - endTime[i]) - (startTime[st] - endTime[st]);
            ++st;
            ans = max(now, ans);
        }
        return ans;
    }
};
