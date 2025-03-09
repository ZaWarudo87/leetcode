class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0, buffer = 1;
        for(int i = 1, len = colors.size(); i < len + k - 1; ++i){
            buffer = (colors[i % len] == colors[(i - 1) % len] ? 1 : buffer + 1);
            if(buffer >= k)
                ++ans;
        }
        return ans;
    }
};
