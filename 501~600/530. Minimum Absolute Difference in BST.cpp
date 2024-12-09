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
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 100000;
        queue<TreeNode*> qq;
        vector<int> srt;
        srt.reserve(10000);
        qq.push(root);
        while(!qq.empty()){
            srt.emplace_back(qq.front()->val);
            if(qq.front()->left){
                //ans = min(ans, qq.front()->val - qq.front()->left->val);
                qq.push(qq.front()->left);
            }
            if(qq.front()->right){
                //ans = min(ans, qq.front()->right->val - qq.front()->val);
                qq.push(qq.front()->right);
            }
            qq.pop();
        }
        sort(srt.begin(), srt.end());
        for(auto i = srt.begin() + 1; i != srt.end(); i++){
            if(*i - *(i - 1) < ans)
                ans = *i - *(i - 1);
        }
        return ans;
    }
};
