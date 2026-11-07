class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        dup = -1
        miss = -1

        for i in range(len(nums)):
            idx = abs(nums[i])-1

            if nums[idx] < 0:
                dup = abs(nums[i])
            else:
                nums[idx] *= -1
            
        for i in range(len(nums)):
            if nums[i] > 0:
                miss = i+1
                break


        return [dup,miss]