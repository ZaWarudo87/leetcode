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
    int pretable[31], posttable[31];

    void build(TreeNode *&root, vector<int> &preorder, vector<int> &postorder, int prel, int prer, int postl, int postr){
        int leftNodeVal = preorder[prel], rightNodeVal = postorder[postr];
        root->left = new TreeNode(leftNodeVal);
        if(postl < posttable[leftNodeVal]){
            build(root->left, preorder, postorder, prel + 1, (rightNodeVal != leftNodeVal ? pretable[rightNodeVal] - 1 : prer), postl, posttable[leftNodeVal] - 1);
        }
        if(rightNodeVal != leftNodeVal){
            root->right = new TreeNode(rightNodeVal);
            if(pretable[rightNodeVal] < prer)
                build(root->right, preorder, postorder, pretable[rightNodeVal] + 1, prer, posttable[leftNodeVal] + 1, postr - 1);
        }
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int len = preorder.size();
        for(int i = 0; i < len; ++i){
            pretable[preorder[i]] = i;
            posttable[postorder[i]] = i;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        if(len > 1)
            build(root, preorder, postorder, 1, len - 1, 0, len - 2);
        return root;
    }
};
