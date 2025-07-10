class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int len = startTime.size(), ansl = 0, ansr = 0, tmpf = 0;
        startTime.push_back(eventTime);
        endTime.insert(endTime.begin(), 0);
        for(int i = 0; i < len; ++i){
            ansl = max(ansl, startTime[i + 1] - endTime[i] - (endTime[i + 1] - startTime[i] > tmpf ? endTime[i + 1] - startTime[i] : 0));
            tmpf = max(tmpf, startTime[i] - endTime[i]);
        }
        tmpf = 0;
        for(int i = len; i > 0; --i){
            ansr = max(ansr, startTime[i] - endTime[i - 1] - (endTime[i] - startTime[i - 1] > tmpf ? endTime[i] - startTime[i - 1] : 0));
            tmpf = max(tmpf, startTime[i] - endTime[i]);
        }
        return max(ansl, ansr);
    }
};
