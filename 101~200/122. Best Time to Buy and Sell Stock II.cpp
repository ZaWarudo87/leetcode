class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int now = prices[0], ans = 0;
        for(int i = 1, len = prices.size(); i < len - 1; ++i){
            if(now > prices[i])
                now = prices[i];
            else if(prices[i + 1] < prices[i]){
                ans += prices[i] - now;
                now = prices[i + 1];
            }
        }
        if(prices.back() > now)
            ans += prices.back() - now;
        return ans;
    }
};
