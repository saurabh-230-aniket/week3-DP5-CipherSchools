class Solution {
public:
    int rec(int i,int j,string& s,string& r,vector<vector<int>>& dp){
        if(i==-1)
            return j+1;
        if(j==-1)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==r[j])
            return dp[i][j]=rec(i-1,j-1,s,r,dp);
        
        return dp[i][j]=1+min({rec(i-1,j,s,r,dp),rec(i,j-1,s,r,dp),rec(i-1,j-1,s,r,dp)});
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();

        
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<=n;i++)
            dp[0][i]=i;
   
         for(int i=0;i<=m;i++)
            dp[i][0]=i;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                }
            }
        }
        return dp[m][n];
    }
};