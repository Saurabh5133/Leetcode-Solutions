class Solution {
public:
    int arrangeCoins(int n) {
        
        long long i = 0;
        long long j = n;

        int ans = 0;

        while(i<=j)
        {
            long long mid = i+(j-i)/2;

            if(mid*(mid+1)/2 <= n)
                i = mid+1; 
            else
                j= mid-1; 
        }
        return j;
    }
};