class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int len = A.size();
        bool num[51] = {};
        vector<int> ans(len + 1);
        for(int i = 0; i < len; i++){           
            if(num[A[i]])
                ++ans[i];
            num[A[i]] = 1;
            if(num[B[i]])
                ++ans[i];
            num[B[i]] = 1;
            ans[i + 1] = ans[i]; 
        }
        ans.erase(ans.end() - 1, ans.end());
        return ans;
    }
};
