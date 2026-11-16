class Solution(object):
    def largeGroupPositions(self, s):
        """
        :type s: str
        :rtype: List[List[int]]
        """

        ans = []
        i = 0
        n = len(s)

        while i<n:
            j = i

            while j<n and s[j] == s[i]:
                j += 1

            if j-i >= 3:
                ans.append([i,j-1])

            i = j

        return ans



        