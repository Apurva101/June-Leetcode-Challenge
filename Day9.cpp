/*
Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true

*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int m=s.length();
        int n=t.length();
        
        int count=0;
        
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        
       
       
      for(int i=0;i<=m;++i)
        { 
          for(int j=0;j<=n;++j)
          {
             if(i==0 || j==0)
                 dp[i][j]=0;
              
            else  if(s[i-1]==t[j-1])
                {  
                    dp[i][j]=1+dp[i-1][j-1];
                   
                }
            else
            {  dp[i][j]=dp[i][j-1];
            
            }
        
        }
      } 
        
        cout<<dp[m][n]<<" ";
        return (dp[m][n]==m);
        
        
        
    }
};
