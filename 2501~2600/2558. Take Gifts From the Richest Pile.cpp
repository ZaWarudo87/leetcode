class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        int aft;
        priority_queue<int> srt;
        for(int &i : gifts){
            ans += i;
            srt.push(i);
        }
        while(k--){
            aft = sqrt(srt.top());
            ans = ans - srt.top() + aft;
            srt.pop();
            srt.push(aft);
        }
        return ans;
    }
};
