class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, memo[3] = {};
        for(int st = 0, ed = 0, len = s.size(); ed < len; ++ed){
            int d = s[ed] - 'a';
            ++memo[d];
            while(memo[0] && memo[1] && memo[2]){
                ans += len - ed;
                int c = s[st++] - 'a';
                --memo[c];
            }
        }
        return ans;
    }
};
