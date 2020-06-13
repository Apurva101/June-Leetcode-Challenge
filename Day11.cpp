/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int start=0,mid=0,end=nums.size()-1;
        
        while(mid<=end)
        {
            if(nums[mid]==0)
            {
                swap(nums[start],nums[mid]);
                start++;
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid], nums[end]);
                end--;
            }
            else
                mid++;
        }
    }
};
