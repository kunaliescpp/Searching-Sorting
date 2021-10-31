/*
Problem Link: https://leetcode.com/problems/split-array-largest-sum/

Split Array Largest Sum

Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty 
continuous subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.

Example 1:
Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays. The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

Example 2:
Input: nums = [1,2,3,4,5], m = 2
Output: 9

Example 3:
Input: nums = [1,4,4], m = 3
Output: 4
 
Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 10^6
1 <= m <= min(50, nums.length)
*/


class Solution {
public:
   bool isFeasible(vector<int> arr, int n, int m, int number){
        
        int cnt = 1, Sum = 0;                               // error : cnt == 0
        for(int i = 0; i < n; i++){
            
            if(Sum + arr[i] <= number){
                Sum += arr[i];
            } else {
                cnt++, Sum = arr[i];
            }
            
            if(cnt > m) return false;
        }
      return true;
    }
    
    int splitArray(vector<int>& arr, int m) {
        
        int n = arr.size();
      // result is must be in btw [max_element, arrSum]
      int sum = 0, maxi = 0;
       for(int i = 0; i < n; i++){
           sum += arr[i];
           maxi = max(maxi, arr[i]);
       }
      
      int start = maxi, end = sum; 
      int ans = 0;
      while(start <= end){
          
          int mid = start +  (end - start)/2;
          
          // if fesible, go to the left half
          if(isFeasible(arr, n, m, mid) == true){
              ans = mid;
              end = mid-1;
          }
          //else go to the right half
          else start = mid + 1; 
      }
      
    return ans;  
    }
};




