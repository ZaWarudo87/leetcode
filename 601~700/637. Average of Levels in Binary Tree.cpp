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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<long long, int> > sum;
        queue<pair<TreeNode*, int> > qq;
        qq.push(make_pair(root, 0));
        while(!qq.empty()){
            if(qq.front().first){
                if(sum.size() <= qq.front().second)
                    sum.emplace_back(make_pair(0, 0));
                sum[qq.front().second].first += qq.front().first->val;
                ++sum[qq.front().second].second;
                qq.push(make_pair(qq.front().first->left, qq.front().second + 1));
                qq.push(make_pair(qq.front().first->right, qq.front().second + 1));
            }
            qq.pop();
        }

        int len = sum.size();
        vector<double> ans(len);
        for(int i = 0; i < len; ++i)
            ans[i] = double(sum[i].first) / sum[i].second;
        return ans;
    }
};
