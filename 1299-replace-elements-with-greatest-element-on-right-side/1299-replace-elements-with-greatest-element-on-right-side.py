class Solution(object):
    def replaceElements(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """

        n = len(arr)
        greatest = [0]*n
        
        greatest[n-1] = -1
        m = arr[n-1]

        for i in range(n-2, -1, -1):
            m = max(m, arr[i+1])
            greatest[i] = m

        return greatest

        

            
        