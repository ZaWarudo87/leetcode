class Solution {
public:
    bool canConstruct(string s, int k) {
        int alphabet[26] = {}, now = 0;
        for (char& i : s)
            ++alphabet[i - 'a'];
        for (int i = 0; i < 26; ++i)
            now += alphabet[i] % 2;
        return now <= k && s.size() >= k;
    }
};
