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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode *red;
        queue<TreeNode*> qq;
        qq.push(root);
        while(!qq.empty()){
            if(!qq.front()){
                qq.pop();
                continue;
            }
            if(qq.front()->val == x){
                red = qq.front();
                break;
            }
            qq.push(qq.front()->left);
            qq.push(qq.front()->right);
            qq.pop();
        }
        
        int l = 0, r = 0;
        queue<TreeNode*> qql, qqr;
        qql.push(red->left);
        while(!qql.empty()){
            if(!qql.front()){
                qql.pop();
                continue;
            }
            qql.push(qql.front()->left);
            qql.push(qql.front()->right);
            ++l;
            qql.pop();
        }
        qqr.push(red->right);
        while(!qqr.empty()){
            if(!qqr.front()){
                qqr.pop();
                continue;
            }
            qqr.push(qqr.front()->left);
            qqr.push(qqr.front()->right);
            ++r;
            qqr.pop();
        }
        int rd = l + r + 1;
        return int(n / 2) >= rd || l > n - l || r > n - r;
    }
};
