class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name[0] != typed[0]) return false;
        int i = 1, j = 1, len = name.size(), len2 = typed.size();
        for(; i < len2; ++i){
            if(j >= len) break;
            
            if(typed[i] == name[j]){
                ++j;
                continue;
            }else if(typed[i - 1] == typed[i]){
                continue;
            }else{
                return false;
            }
        }
        for(; i < len2; ++i){
            if(name[len - 1] != typed[i])
                return false;
        }
        return name[len - 1] == typed[len2 - 1] && j >= len;
    }
};
