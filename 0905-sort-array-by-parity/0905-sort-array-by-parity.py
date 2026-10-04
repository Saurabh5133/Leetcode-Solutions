class Solution(object):
    def sortArrayByParity(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        ans = [0]*n
        l = 0
        r = n-1
        for i in range(n):
            if nums[i]%2 == 0:
                ans[l] = nums[i]
                l += 1
            else:
                ans[r] = nums[i]
                r -= 1

        return ans

        
        