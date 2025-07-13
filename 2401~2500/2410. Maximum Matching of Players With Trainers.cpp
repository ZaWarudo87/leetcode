class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans = 0, p = players.size() - 1, t = trainers.size() - 1;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        while(p >= 0 && t >= 0){
            if(players[p] <= trainers[t]){
                ++ans;
                --t;
            }
            --p;
        }
        return ans;
    }
};
