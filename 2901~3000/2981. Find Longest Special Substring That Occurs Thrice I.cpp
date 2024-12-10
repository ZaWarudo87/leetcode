class Solution {
public:
    int maximumLength(string s) {
        map<char, map<int, int, greater<int>>> str;  // {"char" : {conti_len : repeat_times}}
        int len = s.size(), now = 0, ans = -1, temp = 0;
        char bef = s[0];
        for(int i = 0; i < len; i++){
            if(bef == s[i]) temp++;
            else{
                str[bef][temp]++;
                temp = 1;
            }
            bef = s[i];
        }
        str[bef][temp]++;

        for(auto &i : str){
            temp = 0;
            for(int j = i.second.begin()->first; j > 0; j--){
                temp = temp * 2 + i.second[j];
                if(temp >= 3){
                    ans = max(ans, j);
                    break;
                }
            }
        }
        return ans;
    }
};
