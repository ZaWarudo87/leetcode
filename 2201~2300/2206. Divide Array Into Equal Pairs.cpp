class Solution {
public:
    bool divideArray(vector<int>& nums) {
        short fail = 0;
        bool check[501] = {};
        for(int &i : nums){
            if(check[i]){
                --fail;
                check[i] = 0;
            }else{
                ++fail;
                check[i] = 1;
            }
        }
        return fail == 0;
    }
};
