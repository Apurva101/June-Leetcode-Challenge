/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3

*/
class Solution {
public:
    int singleNumber(vector<int>& A) {
        
       //int count = {0};
        int n=A.size();
    int result = 0;
    for (int i = 0; i < 32; i++) {
        int count=0;
        for (int j = 0; j < n; j++) {
            if (A[j] & (1 << i))
            {
                count++;
            }
        }
        result |= ((count % 3) << i);
    }
    return result;
        }
        
      
    
};
