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
class FindElements {
public:
    bool check[10001] = {};

    FindElements(TreeNode* root) {
        queue<pair<TreeNode*, int> > qq;
        qq.push(make_pair(root, 0));
        while(!qq.empty()){
            if(qq.front().first){
                if(qq.front().second < 10001)
                    check[qq.front().second] = 1;
                qq.push(make_pair(qq.front().first->left, qq.front().second * 2 + 1));
                qq.push(make_pair(qq.front().first->right, qq.front().second * 2 + 2));
            }
            qq.pop();
        }
    }
    
    bool find(int target) {
        return check[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
