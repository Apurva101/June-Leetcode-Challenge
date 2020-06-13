/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1


*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(coins.size()==0 && amount==0)
            return 1;
        if(coins.size()==0)
            return 0;
        int dp[coins.size()][amount+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<coins.size();++i)
            dp[i][0]=1;
        
       
        for(int i=0;i<coins.size();++i)
        {
            for(int j=0;j<=amount;++j)
            {
                if(coins[i]<=j)
                {
                    if(i-1>=0)
                 dp[i][j]=dp[i][j-coins[i]] + dp[i-1][j];
                    else if(j-coins[i]>=0)
                        dp[i][j]=dp[i][j-coins[i]];
                    
                }
                else
                    if(i-1>=0)
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[coins.size()-1][amount];
        
    }
};
