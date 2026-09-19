class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        vector<int> prefixSum(k+1,0);
        vector<int> suffixSum(k+1,0);
        int n = cardPoints.size();

        int maxScore = 0;

        for(int i = 1; i<=k; i++)
        {
            prefixSum[i] = cardPoints[i-1] + prefixSum[i-1];
        }

        for(int i = 1; i<=k; i++)
        {
            suffixSum[i] = suffixSum[i-1] + cardPoints[n-i];
        }

        for(int i = 0; i<=k; i++)
        {
            int score = prefixSum[i] + suffixSum[k-i];
            maxScore = max(score, maxScore);
        }

        return maxScore;

    }
};