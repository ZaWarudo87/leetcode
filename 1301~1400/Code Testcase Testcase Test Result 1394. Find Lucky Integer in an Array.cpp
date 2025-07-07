class Solution {
public:
    int findLucky(vector<int>& arr) {
        short test[501] = {}, big = 0;
        for(int &i : arr){
            ++test[i];
            if(big < i)
                big = i;
        }
        
        for(short i = big; i > 0; --i)
            if(test[i] == i)
                return i;
        return -1;
    }
};
