class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        string X = to_string(x);
        for(int i = 0, len = X.size(); i < int(len / 2); i++){
            if(X[i] != X[len - i - 1])
                return false;
        }
        return true;
    }
};
