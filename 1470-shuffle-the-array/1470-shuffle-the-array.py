class Solution(object):
    def shuffle(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: List[int]
        """

        ans = []
        j = n
        for i in range(n):
            ans.append(nums[i])
            ans.append(nums[j])
            j += 1
        
        return ans

        