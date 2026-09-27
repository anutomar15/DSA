class Solution {
public:
    int fibDP(int n, vector<int> &dp){
        // Base Case
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = fibDP(n-1,dp) +fibDP(n-2,dp);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n+1);
        for(int i=0; i<=n; i++){
            dp[i]=-1;
        }
        return fibDP(n,dp);
    }
};