class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        short i, j, k = 0, str1len = str1.size(), str2len = str2.size(), dp[1001][1001] = {};
        for(i = str1len - 1; i >= 0; --i){
            for(j = str2len - 1; j >= 0; --j){
                if(str1[i] == str2[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        string ans(str1len + str2len - dp[0][0], '\n');
        i = 0;
        j = 0;
        while(i < str1len && j < str2len){
            if(str1[i] == str2[j]){
                ans[k++] = str1[i++];
                ++j;
            }else if(dp[i + 1][j] > dp[i][j + 1])
                ans[k++] = str1[i++];
            else
                ans[k++] = str2[j++];
        }
        for(; i < str1len; ++i)
            ans[k++] = str1[i];
        for(; j < str2len; ++j)
            ans[k++] = str2[j];
        return ans;
    }
};
