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
public:
    vector<int> largestValues(TreeNode* root) {
        queue<pair<TreeNode*, int> > qq;
        vector<int> ans(10000, INT_MIN);
        int ed = 0;
        qq.push(make_pair(root, 0));
        while(!qq.empty()){
            if(!qq.front().first){
                ed = max(ed, qq.front().second);
                qq.pop();
                continue;
            }

            ans[qq.front().second] = max(ans[qq.front().second], qq.front().first->val);
            qq.push(make_pair(qq.front().first->left, qq.front().second + 1));
            qq.push(make_pair(qq.front().first->right, qq.front().second + 1));
            qq.pop();
        }
        ans.erase(ans.begin() + ed, ans.end());
        return ans;
    }
};
