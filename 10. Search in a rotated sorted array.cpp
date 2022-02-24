/*
Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such 
that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, 
[0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 
if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
 

Constraints:
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4
*/


class Solution {
public:
    //Logic : Any index on the rotated sorted array have 1 half sorted either left or right.
    //Time complexity: O(ceiling of log base 2 n) = O(log n);
    int search(vector<int>& nums, int x) {
        
        int n = nums.size();
        int start = 0, end = n-1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == x) return mid;
            
            if(nums[start] <= nums[mid]){
            //left half sorted
                if(x >= nums[start] && x < nums[mid]) end = mid - 1;
                else start = mid + 1;
            } 
            
            else{
            //right half sorted 
                if(x > nums[mid] && x <= nums[end]) start = mid + 1;
                else end = mid - 1;
            }
        }
   return -1;  
    }
};

// if(x >= nums[start] && x <= nums[mid-1]) 
// this gives runtime error when arr contains only 1 element. i.e. arr = [1], x = 2               
