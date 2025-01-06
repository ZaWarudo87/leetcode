class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int len = s.size();
        vector<int> box(len + 1);
        for(const vector<int> &i : shifts){
            box[i[0]] = (box[i[0]] + (i[2] ? 1 : -1) + 26) % 26;
            box[i[1] + 1] = (box[i[1] + 1] - (i[2] ? 1 : -1) + 26) % 26;
        }
        for(int i = 0, shifter = 0; i < len; ++i){
            shifter += box[i];
            s[i] = (s[i] + shifter - 'a') % 26 + 'a';
        }
        return s;
    }
};
