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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int best = 0;
        queue<TreeNode*> qq;
        qq.push(root);
        root->val = 1;
        while(!qq.empty()){
            if(!qq.front()->left){
                if(qq.front()->val > best)
                    best = qq.front()->val;
            }else{
                qq.front()->left->val = qq.front()->val + 1;
                qq.push(qq.front()->left);
            }
            if(!qq.front()->right){
                if(qq.front()->val > best)
                    best = qq.front()->val;
            }else{
                qq.front()->right->val = qq.front()->val + 1;
                qq.push(qq.front()->right);
            }
            qq.pop();
        }
        return best;
    }
};
