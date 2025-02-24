class Solution {
public:
    vector<vector<int> > mapu;

    pair<int, int> dfs(int now, int bef, int step, int &bob, vector<int> &amount){
        int income = INT_MIN, bobStep = -1;
        pair<int, int> child;
        for(int &i : mapu[now]){
            if(i != bef){
                child = dfs(i, now, step + 1, bob, amount);
                income = max(income, child.first);
                bobStep = max(bobStep, child.second);
            }
        }
        if(income == INT_MIN) income = 0;
        if(now == bob) bobStep = 0;
        else if(bobStep > -1) ++bobStep;
        income += (bobStep == -1 || bobStep > step ? amount[now] : (bobStep == step ? amount[now] / 2 : 0));
        //cout << now << ": " << income << ", " << bobStep << '\n';
        return make_pair(income, bobStep);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        mapu.resize(n);
        for(vector<int> &i : edges){
            mapu[i[0]].emplace_back(i[1]);
            mapu[i[1]].emplace_back(i[0]);
        }
        return dfs(0, -1, 0, bob, amount).first;
    }
};
