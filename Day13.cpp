/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0)
            return {};
        vector<int>res;
        vector<int> pre(nums.size(),-1);
        vector<int> count(nums.size(),1);
        int ans=0, index=-1;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size();++i)
        {
            
            for(int j=i-1;j>=0;--j)
            {
                if(nums[i]%nums[j]==0 && count[j]+1>count[i])
                {
                    count[i]=count[j]+1;
                    pre[i]=j;
                }
                
            }
                if(count[i]>ans)
                {
                    ans=count[i];
                    index=i;
                }
            
        }
        
        while(index!=-1)
        {
           res.push_back(nums[index]);
            index=pre[index];
        }
        return res;
    }
};
