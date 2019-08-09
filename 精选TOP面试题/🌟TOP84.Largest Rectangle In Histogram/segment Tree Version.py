#
# 写的太臭了…… python的代码和c的一样长
#
#
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        tree = SegmentTree.buildTree(0, len(heights)-1, heights)
        return self.getAns(tree, 0, len(heights)-1, heights)

    def getAns(self, root, start: int, end: int, heights: List[int]):
        if start > end:
            return 0
        if start == end:
            return heights[start]
        min_index = root.query(start, end, heights)
        # print(min_index)
        if min_index == -1:
            print('error:index out of range')
            return
        return max(heights[min_index]*(end-start+1), self.getAns(root, start, min_index-1, heights), self.getAns(root, min_index+1, end, heights))


class SegmentTree:
    def __init__(self, start: int, end: int):
        self.left = None
        self.right = None
        self.start = start
        self.end = end
        self.min = 0

    @staticmethod
    def buildTree(start: int, end: int, heights: List[int]):
        if start > end:
            return None
        root = SegmentTree(start, end)
        if end == start:
            root.min = start  # 保存的最小值是下标而不是值
        else:
            mid = (start+end)//2
            root.left = SegmentTree.buildTree(start, mid, heights)
            root.right = SegmentTree.buildTree(mid+1, end, heights)
            root.min = root.left.min if heights[root.left.min] < heights[root.right.min] else root.right.min

        return root

    def query(self, start: int, end: int, heights: List[int]) -> int:
        if end < self.start or start > self.end:
            return -1  # 没找到返回-1 因为index不可能是负数
        if end >= self.end and start <= self.start:
            return self.min
        left_min = self.left.query(start, end, heights)
        right_min = self.right.query(start, end, heights)

        if left_min < 0:
            return right_min
        if right_min < 0:
            return left_min
        return left_min if heights[left_min] < heights[right_min] else right_min



