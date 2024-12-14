class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> iso, iso2;
        for(int i = 0, len = s.size(); i < len; i++){
            if(iso.count(s[i]) && iso[s[i]] != t[i] || iso2.count(t[i]) && iso2[t[i]] != s[i]) return false;
            iso[s[i]] = t[i];
            iso2[t[i]] = s[i];
        }
        return true;
    }
};
