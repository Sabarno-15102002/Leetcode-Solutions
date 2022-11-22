class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        int i,j;
        for(i=1;i<=n;++i){
            dp[i]=i;
            for(j=1;i-(j*j) >= 0; ++j)
                dp[i] = min(dp[i], dp[i-(j*j)]+1);
        }
        return dp[n];
    }
};