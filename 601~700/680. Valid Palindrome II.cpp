class Solution {
public:
    bool validPalindrome(string s) {
        bool sk = 1, md;
        int st = 0, ed = s.size() - 1, sts, eds;
        while(st < ed){
            if(s[st] != s[ed]){
                if(sk){
                    sk = 0;
                    sts = st;
                    eds = ed;
                    if(s[st] == s[ed - 1]){
                        md = 0;
                        ed--;
                    }
                    else if(s[st + 1] == s[ed]){
                        md = 1;
                        st++;
                    }
                    else 
                        return false;
                }else{
                    st = sts;
                    ed = eds;
                    if(md || s[st + 1] != s[ed]){
                        return false;
                    }else{
                        md = 1;
                        st++;
                    }
                }
            }
            st++;
            ed--;
        }
        return true;
    }
};
