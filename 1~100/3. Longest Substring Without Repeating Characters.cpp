class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int ans = 1, st = 0, ed = 1, len = s.size();
        bool ch[256] = {};
        ch[s[0]] = 1;
        while(ed < len){
            while(ch[s[ed]])
                ch[s[st++]] = 0;
            ans = max(ans, ed - st + 1);
            //cout << st << ' ' << ed << ' ' << ed - st + 1 << '\n';
            ch[s[ed++]] = 1;
        }
        return ans;
    }
};
