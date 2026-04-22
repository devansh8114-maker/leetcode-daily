class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def f(start, end):
            if start > end:   # correct base case
                return None
            
            mid = (start + end) // 2
            root = TreeNode(nums[mid])
            
            root.left = f(start, mid - 1)
            root.right = f(mid + 1, end)
            
            return root
        
        return f(0, len(nums) - 1)