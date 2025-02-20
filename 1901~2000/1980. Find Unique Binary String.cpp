class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int len = nums.size();
        bool check[65536] = {};
        for(string &i : nums)
            check[bitset<16>(i).to_ulong()] = 1;
        for(int i = 0; i < 65536; ++i)
            if(!check[i])
                return bitset<16>(i).to_string().substr(16 - len, len);
        return "1111111111111111";
    }
};
