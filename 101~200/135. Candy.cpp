class Solution {
public:
    int candy(vector<int>& ratings) {
        int st[20000] = {1}, ed[20000] = {}, ans = 0, len = ratings.size();
        ed[len - 1] = 1;
        for(int i = 1; i < len; i++)
            st[i] = (ratings[i] > ratings[i - 1] ? st[i - 1] + 1 : 1);
        ans += max(st[len - 1], ed[len - 1]);
        for(int i = len - 2; i >= 0; i--){
            ed[i] = (ratings[i] > ratings[i + 1] ? ed[i + 1] + 1 : 1);
            ans += max(st[i], ed[i]);
        }
        return ans;
    }
};
