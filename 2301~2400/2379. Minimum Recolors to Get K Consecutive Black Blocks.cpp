class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        short len = blocks.size(), ans, now = 0;
        for(short i = 0; i < k; ++i)
            now += blocks[i] == 'W';
        ans = now;
        for(short i = 1; i + k <= len; ++i){
            now = now - (blocks[i - 1] == 'W') + (blocks[i + k - 1] == 'W');
            ans = min(ans, now);
        }
        return ans;
    }
};
