class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m[26] = {};
        int lenr = ransomNote.size(), lenm = magazine.size();
        if(lenr > lenm) return false;
        for(int i = 0; i < lenr; i++){
            --m[ransomNote[i] - 'a'];
            ++m[magazine[i] - 'a'];
        }
        for(int i = lenr; i < lenm; i++)
            ++m[magazine[i] - 'a'];
        for(int i = 0; i < 26; i++){
            if(m[i] < 0)
                return false;
        }
        return true;
    }
};
