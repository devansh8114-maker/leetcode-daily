# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def bstToGst(self, root):
        total =0
        Stack=[]
        new_root=root
        while Stack or root:
            while root:
                Stack.append(root)
                root=root.right
            root=Stack.pop()
            total=total+root.val
            root.val=total
            root=root.left
        return new_root        