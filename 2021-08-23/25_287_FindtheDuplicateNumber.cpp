/*
https://leetcode.com/problems/find-the-duplicate-number/

287_FindtheDuplicateNumber

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) ;
    
            nums[index] *= -1;
        
            if(nums[index] > 0)
                return abs(nums[i]);
        }    
        return -1;
    }
};