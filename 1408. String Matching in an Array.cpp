class Solution {
private:
    static bool comp(string a, string b){
        return a.size() < b.size();
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        int i, j, len = words.size();
        vector<string> ans;
        ans.reserve(len);
        sort(words.begin(), words.end(), Solution::comp);
        for(i = 0; i < len; i++){
            for(j = i + 1; j < len; j++){
                if(words[j].find(words[i]) != string::npos){
                    ans.emplace_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
