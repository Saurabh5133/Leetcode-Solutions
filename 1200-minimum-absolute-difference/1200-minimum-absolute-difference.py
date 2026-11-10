class Solution(object):
    def minimumAbsDifference(self, arr):
        """
        :type arr: List[int]
        :rtype: List[List[int]]
        """

        arr.sort()
        mini = float('inf')

        for i in range(1, len(arr)):
            mini = min(mini, arr[i]-arr[i-1])

        ans = []

        for i in range(1, len(arr)):
            if arr[i] - arr[i-1] == mini:
                ans.append([arr[i-1],arr[i]])

        return ans
        