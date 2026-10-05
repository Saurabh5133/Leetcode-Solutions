class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        ans = [0]*n
        i = 0
        j = n-1
        k = n-1

        for _ in range(n):
            if nums[i]*nums[i] >= nums[j]*nums[j]:
                ans[k] = nums[i]*nums[i]
                i += 1
            else:
                ans[k] = nums[j]*nums[j]
                j -= 1

            k -= 1

        return ans      