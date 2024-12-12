class Solution {
private:
    void dfs(const string &num, int target, vector<string> &ans, int idx, string nowExp, long long nowAns, long long prevOperand){
        int len = num.size();
        if(idx == len){
            if(nowAns == target) ans.emplace_back(nowExp);
            return;
        }

        long long temp = 0;
        string tempStr;

        for(int i = idx; i < len; ++i){
            if(i > idx && num[idx] == '0') break;

            temp = temp * 10 + (num[i] - '0');
            tempStr = num.substr(idx, i - idx + 1);

            if(idx == 0)
                dfs(num, target, ans, i + 1, tempStr, temp, temp);
            else{
                dfs(num, target, ans, i + 1, nowExp + "+" + tempStr, nowAns + temp, temp);
                dfs(num, target, ans, i + 1, nowExp + "-" + tempStr, nowAns - temp, -temp);
                dfs(num, target, ans, i + 1, nowExp + "*" + tempStr, nowAns - prevOperand + prevOperand * temp, prevOperand * temp);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        ans.reserve(num.size());
        dfs(num, target, ans, 0, "", 0, 0);
        return ans;
    }
};
