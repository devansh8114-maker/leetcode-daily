# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findBottomLeftValue(self, root):
        Q=[root]
        x=root.val
        while Q:
            size=len(Q)
            for i in range(size):
                node=Q.pop(0)
                if i==0:
                    x=node.val
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)
        return x                