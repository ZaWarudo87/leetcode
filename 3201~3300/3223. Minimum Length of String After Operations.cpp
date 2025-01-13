class Solution {
public:
    int minimumLength(string s) {
        int ans = 0, alphabet[26] = {};
        for(char &i : s)
            ++alphabet[i - 'a'];
        for(int i = 0; i < 26; ++i)
            ans += (alphabet[i] ? (alphabet[i] % 2 ? 1 : 2) : 0);
        return ans;
    }
};
