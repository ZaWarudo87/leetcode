class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int len = pattern.size();
        if(len - 1 != count(s.begin(), s.end(), ' ')) return false;
        unordered_map<char, string> iso;
        unordered_map<string, char> iso2;
        size_t fd, st = 0;
        string temp;
        for(int i = 0; i < len; i++){
            fd = s.find(' ', st);
            temp = s.substr(st, fd - st);
            if(iso.count(pattern[i]) && iso[pattern[i]] != temp || iso2.count(temp) && iso2[temp] != pattern[i]) return false;
            iso[pattern[i]] = temp;
            iso2[temp] = pattern[i];
            st = fd + 1;
        }
        return true;
    }
};
