class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans = "0";
        int len;
        if(a.size() < b.size()){
            len = b.size();
            for(int i = a.size(); i < len; i++)
                a += "0";
        }else{
            len = a.size();
            for(int i = b.size(); i < len; i++)
                b += "0";
        }
        for(int i = 0; i < len; i++){
            if(a[i] == '1' && b[i] == '1')
                ans += "1";
            else if((a[i] == '1' || b[i] == '1') && ans[i] == '1'){
                ans += "1";
                ans[i] = '0';
            }else if(a[i] == '1' || b[i] == '1'){
                ans[i] = '1';
                ans += "0";
            }else
                ans += "0";
        }
        while(*(ans.end() - 1) == '0' && ans.size() > 1)
            ans.erase(ans.end() - 1, ans.end());
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
