/*
Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such 
that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, 
[0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 
if it is not in nums.

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

// can be (not either) minimize or maximize idx
int search(vector<int>& nums, int target) {
    int n = nums.size();

    int l = 0, r = n-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(nums[mid] == target) return mid;

        else if(l == r || l+1 == r){ 
            if(nums[r] == target) return r;
            else return -1;
        } 

        // if left portion sorted, then ask direction
        else if(nums[l] <= nums[mid-1]){
            if(target >= nums[l] && target <= nums[mid-1]) r = mid-1;
            else l = mid+1;
        } 

        // if right portion sorted, then ask direction
        else if(nums[mid+1] <= nums[r]){
            if(target >= nums[mid+1] && target <= nums[r]) l = mid+1;
            else r = mid-1;
        }      
    }
return -1;
}

// if(x >= nums[start] && x <= nums[mid-1]) 
// this gives runtime error when arr contains only 1 element. i.e. arr = [1], x = 2   
