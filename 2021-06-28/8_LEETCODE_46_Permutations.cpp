/*

https://leetcode.com/problems/permutations/
46_Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

class Solution {
public:
    vector<vector<int>> ans;
    
    void backtracking(int first, vector<int>& nums){
        if (first == nums.size()) 
        {
            ans.push_back(nums);
        }
        else
        {
            for (int i = first; i < nums.size(); i++)
            {
                swap(nums[first], nums[i]);
                backtracking(first + 1, nums);
                swap(nums[first], nums[i]);
            }
        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        backtracking(0, nums);
        return ans;
    }
};