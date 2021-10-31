/* 
Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:
Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:
Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:
Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

class Solution {
public:
   // Median : Middle value's mean (two middle values or one middle value)
   // Approach :we assume that nums1.size() < nums2.size(). If our assumption is not true then we changepointers.1
   // Time complexity: O(log n1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size();
        if(n2 < n1) return findMedianSortedArrays(nums2,nums1);
        
        int start1 = 0, end1 = n1;
        while(start1 <= end1){
            // left half of nums1 + left half of nums2 = right half of nums1 + right half of nums2
            int i1 = (start1 + end1)/ 2;
            int i2 = (n2 + n1 + 1)/2 - i1;
            
            //maxi pointer is at  i-1 & mini pointer is at i
            int mini1 = (i1 == n1) ? INT_MAX : nums1[i1]; 
            int maxi1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1]; 
            
            int mini2 = (i2 == n2) ? INT_MAX : nums2[i2]; 
            int maxi2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1]; 
            
            //Iteration
            if(mini1 >= maxi2 && mini2 >= maxi1){
                if((n1 + n2) % 2 == 0) return ((double) max(maxi1, maxi2) +  min(mini1, mini2))/2;
                else return ((double) max(maxi1, maxi2));
            }
            
           else if (mini1 < maxi2) start1 = i1 + 1;          // Aage khiska lo mini 1 ki jyada value chahiye
           else end1 = i1 - 1;                                      // piche le aao maxi 1 jyada aa rha he
        }
    
    return 0.0;
    }
};




