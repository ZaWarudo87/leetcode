class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int i, j, il, jl, len = words.size(), ans = 0;
        for(i = 0; i < len; ++i){
            for(j = i + 1; j < len; j++){
                il = words[i].size();
                jl = words[j].size();
                ans += (words[j].substr(0, il) == words[i] && words[j].substr(jl - il, il) == words[i]);
            }
        }
        return ans;
    }
};
