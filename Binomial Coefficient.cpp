class Solution{

public:

    int nCr(int n, int r){
        int dp[n+1][r+1] = {0};
        int md = 1000000007;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=r; j++){
                if(j==0 || i==j){
                    dp[i][j] = 1;
                    continue;
                }
                if(j>i || i==0){
                    dp[i][j] = 0;
                    continue;
                }
                long long c = dp[i-1][j] + dp[i-1][j-1];
                dp[i][j] = c%md;
            }
        }
        return dp[n][r];
    }
};