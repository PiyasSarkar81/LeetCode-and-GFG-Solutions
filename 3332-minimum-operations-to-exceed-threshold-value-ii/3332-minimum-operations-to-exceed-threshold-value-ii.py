class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        sorted_nums = SortedList(nums)
        op = 0
        while(len(sorted_nums)>=2 and sorted_nums[0] < k):
            new_num = sorted_nums[0]*2 + sorted_nums[1]
            # print(f"new num: {new_num}")
            sorted_nums.pop(0)
            sorted_nums.pop(0)
            sorted_nums.add(new_num)
            # print(sorted_nums[0])
            op = op + 1

        return op