/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    static stack<pair<TreeNode*, int> > bef;

    static TreeNode* find(TreeNode *now, int &nowlay, int tar){
        if(now->right && now->left)
            Solution::bef.push(pair<TreeNode*, int>(now, nowlay));

        nowlay++;
        if(now->right)
            now = now->right;
        else if(now->left)
            now = now->left;
        else{
            if(Solution::bef.empty())
                return 0;
            now = Solution::bef.top().first->left;
            nowlay = Solution::bef.top().second + 1;
            Solution::bef.pop();
        }
        //cout << now->val << " : " << nowlay << '\n';
        if(nowlay < tar){
            //cout << "tar: " << tar << '\n';
            return Solution::find(now, nowlay, tar);
        }else{
            //cout << "return " << now->val << '\n';
            return now;
        }
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        TreeNode *now = root;
        int nowlay = 0;
        while(now){
            ans.push_back(now->val);
            now = Solution::find(now, nowlay, nowlay + 1);
        }
        return ans;
    }
};

stack<pair<TreeNode*, int> > Solution::bef;
