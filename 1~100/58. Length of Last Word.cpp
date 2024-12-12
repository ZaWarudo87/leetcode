class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, i = s.size() - 1;
        while(s[i] == ' ') i--;
        for(; i >= 0 && s[i] != ' '; i--) ans++;
        return ans;
    }
};
