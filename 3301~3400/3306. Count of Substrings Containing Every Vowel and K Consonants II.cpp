class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        auto cntbef = [&](int k) -> long long{
            int con = 0, st = 0, ed = 0, len = word.size(), vow[21] = {};
            short v = 0;
            long long ans = 0;

            auto update = [&](char c, short n) -> void{
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                    vow[c - 'a'] += n;
                    if(vow[c - 'a'] == 0 && n == -1)
                        --v;
                    else if(vow[c - 'a'] == 1 && n == 1)
                        ++v;
                }else
                    con += n;
            };

            while(ed < len){
                update(word[ed], 1);
                while(v == 5 && con >= k){
                    ans += len - ed;
                    update(word[st++], -1);
                }
                ++ed;
            }
            return ans;
        };
        return cntbef(k) - cntbef(k + 1);
    }
};
