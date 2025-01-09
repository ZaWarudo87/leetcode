class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0, pl = pref.size();
        for(string &i : words){
            ans += i.substr(0, pl) == pref;
        }
        return ans;
    }
};
