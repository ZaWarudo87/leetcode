class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mapu;
        int n = nums.size() / 2;
        for(int &i : nums){
            mapu[i]++;
            if(mapu[i] > n) return i;
        }
        return 0;
    }
};
