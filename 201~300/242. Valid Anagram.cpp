class Solution {
public:
    bool isAnagram(string s, string t) {
        int sn[26] = {}, tn[26] = {}, len = s.size();
        if(len != t.size()) return false;
        for(int i = 0; i < len; i++){
            sn[s[i] - 'a']++;
            tn[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(sn[i] != tn[i]) return false;
        }
        return true;
    }
};
