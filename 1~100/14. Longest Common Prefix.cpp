class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i, j, len[200], l = strs.size();
        if(l == 1) return strs[0];
        for(i = 0; i < l; i++) len[i] = strs[i].size();
        for(i = 0; ; i++){
            for(j = 1; j < l; j++){
                if(len[j] <= i || strs[j][i] != strs[j - 1][i])
                    return ans;
            }
            ans += strs[0][i];
            CONTI:
        }
        return ans;
    }
};
