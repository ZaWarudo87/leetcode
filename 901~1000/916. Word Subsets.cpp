class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int total = 0, tmp, check[26] = {}, temp[26];
        for(string &i : words2){
            memset(temp, 0, sizeof(int) * 26);
            for(char &j : i)
                ++temp[j - 'a'];
            for(int j = 0; j < 26; ++j){
                if(temp[j] > check[j]){
                    total += temp[j] - check[j];
                    check[j] = temp[j];
                }
            }
        }

        for(string &i : words1){
            copy(check, check + 26, temp);
            tmp = total;
            for(char &j : i){
                if(temp[j - 'a'] > 0){
                    --temp[j - 'a'];
                    --tmp;
                }
            }
            if(tmp <= 0)
                ans.emplace_back(i);
        }
        return ans;
    }
};
