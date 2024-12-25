/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
private:
    TreeNode *answer = 0;

    pair<bool, bool> isThere(TreeNode *now, TreeNode *p, TreeNode *q){
        if(!now) return make_pair(false, false);
        pair<bool, bool> ansLeft = isThere(now->left, p, q), ansRight = isThere(now->right, p, q);
        pair<bool, bool> ans = make_pair(ansLeft.first || ansRight.first || now == p, ansLeft.second || ansRight.second || now == q);
        if(!(ansLeft.first && ansLeft.second) && !(ansRight.first && ansRight.second) && (ans.first && ans.second))
            answer = now;
        return ans;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        isThere(root, p, q);
        return answer;
    }
};
