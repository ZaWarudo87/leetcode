# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        ans = 0 #待會會把目前看到最深的層記錄進來，所以先初始化為0
        queue = deque([[root, 1]]) #我們這邊開個queue，用來存放要排隊被遍歷的節點以及它所在的層數。首先要被遍歷的就是我們的根節點

        while queue: #只要佇列裡還有人在排隊，就不會結束遍歷
            nowNode, nowDepth = queue[0] #把目前隊伍最前面那位的資訊抓出來，方便後面使用
            if nowNode != None: #確定目前隊伍第一位是真的有節點的，才能執行這些
                ans = max(ans, nowDepth) #更新ans為目前深度最大值

                #讓它的小孩們也都去排隊
                queue.append([nowNode.left, nowDepth + 1])
                queue.append([nowNode.right, nowDepth + 1])
                
            queue.popleft() #處理完成，刪掉最前面那位
        
        return ans
