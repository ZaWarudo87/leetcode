class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, ed = s.size() - 1;
        while(st < ed){
            while(st < s.size() && !isalnum(s[st]))
                st++;
            while(ed >= 0 && !isalnum(s[ed]))
                ed--;
            if(st >= ed)
                break;
            if(tolower(s[st++]) != tolower(s[ed--]))
                return false;
        }
        return true;
    }
};
