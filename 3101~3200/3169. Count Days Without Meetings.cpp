class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int, int> > meet;
        int daymeet = 0, idx, ed, sz, j;
        pair<int, int> now(0, -1);
        meet.push_back(now);
        for(vector<int> &i : meetings){
            now = make_pair(i[0], i[1]);
            sz = meet.size();
            idx = upper_bound(meet.begin(), meet.end(), now) - meet.begin() - 1;
            if(i[0] > meet[idx].second){
                meet.insert(meet.begin() + (++idx), make_pair(i[0], i[0] - 1));
                ++sz;
            }
            ed = idx;
            while(ed < sz && meet[ed].first <= i[1]) ++ed;
            for(j = idx; j < ed; ++j)
                daymeet -= meet[j].second - meet[j].first + 1;
            meet[idx].second = max(i[1], meet[ed - 1].second);
            daymeet += meet[idx].second - meet[idx].first + 1;
            if(idx + 1 < ed)
                meet.erase(meet.begin() + idx + 1, meet.begin() + ed);
        }
        return days - daymeet;
    }
};
