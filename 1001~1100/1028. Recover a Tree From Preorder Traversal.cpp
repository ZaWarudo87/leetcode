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
    int string_to_int(string &str, int &st, int &ed){
        int ans = str[st] - '0';
        for(int i = st + 1; i < ed; ++i){
            ans *= 10;
            ans += str[i] - '0';
        }
        return ans;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int st = 0, ed = 0, nowlay = 0, len = traversal.size(), templay;
        while(ed < len && traversal[ed] != '-') ++ed;
        TreeNode *root = new TreeNode(string_to_int(traversal, st, ed)), *now = root;
        stack<TreeNode*> bef;
        bef.push(root);

        while(ed < len){
            st = ed;
            while(traversal[ed] == '-') ++ed;
            templay = ed - st;
            while(templay <= nowlay){
                --nowlay;
                bef.pop();
            }
            now = bef.top();

            st = ed;
            while(ed < len && traversal[ed] != '-') ++ed;
            if(!now->left){
                now->left = new TreeNode(string_to_int(traversal, st, ed));
                now = now->left;
            }else{
                now->right = new TreeNode(string_to_int(traversal, st, ed));
                now = now->right;
            }
            ++nowlay;
            bef.push(now);
        }
        return root;
    }
};
