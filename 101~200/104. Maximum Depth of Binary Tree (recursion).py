# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        #如果根本沒樹，就代表深度是0
        if root == None:
            return 0

        #遞迴取得自己左子樹跟右子樹的深度，順便加上自己本人
        left = self.maxDepth(root.left) + 1
        right = self.maxDepth(root.right) + 1

        #比較高的那邊即是自己的深度
        return max(left, right)
