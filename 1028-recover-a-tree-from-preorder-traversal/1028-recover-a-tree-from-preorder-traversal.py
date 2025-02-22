# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        stack = []
        idx = 0
        while idx < len(traversal):
            d = 0
            while idx < len(traversal) and traversal[idx] == "-":
                d += 1
                idx += 1
            val = 0
            while idx < len(traversal) and traversal[idx].isdigit():
                val = val * 10 + int(traversal[idx])
                idx += 1
            
            node = TreeNode(val)
            while len(stack) > d:
                stack.pop()

            if stack:
                if stack[-1].left is None:
                    stack[-1].left = node
                else:
                    stack[-1].right = node
            
            stack.append(node)

        return stack[0]
