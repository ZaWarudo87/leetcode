class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.size(), lb = 0, lm = 0, rb = 0, rm = 0;
        vector<int> ans(len);
        for(int i = 0; i < len; ++i){
            ans[i] += lm;
            lb += boxes[i] == '1';
            lm += lb;
            ans[len - i - 1] += rm;
            rb += boxes[len - i - 1] == '1';
            rm += rb;
        }
        return ans;
    }
};
