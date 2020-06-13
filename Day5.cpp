/*

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

For example, given an input list of values [1, 9], when we pick up a number out of it, the chance is that 9 times out of 10 we should pick the number 9 as the answer.

Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]

*/
class Solution {
public:
    vector<int> prob;
    Solution(vector<int>& w) {
        
         prob.push_back(w[0]);
        for(int i=1;i<w.size();++i)
            prob.push_back(prob[i-1]+w[i]);
    }
    
    int pickIndex() {
        
        int num=rand()%prob.back()+1;
        return lower_bound(prob.begin(), prob.end(), num)-prob.begin();
    }
};
