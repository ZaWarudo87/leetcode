class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int st = 0, ed = *max_element(ribbons.begin(), ribbons.end()), mid;
        
        while(st < ed){
            mid = st + (ed - st + 1) / 2;
            if(mid == 0) return 0;
            int temp = 0;
            for(int &r : ribbons){
                temp += r / mid;
                if(temp >= k) break;
            }
            if(temp >= k)
                st = mid;
            else
                ed = mid - 1;
        }
        return st;
    }
};
