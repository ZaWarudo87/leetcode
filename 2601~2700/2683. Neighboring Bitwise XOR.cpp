class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool now = 1;
        for(int &i : derived)
            if(i)
                now = !now;
        return now;
    }
};
