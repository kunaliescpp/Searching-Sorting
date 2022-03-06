/* 
Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.


Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

// TC: O(log min(n, m))
double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
  int m = v1.size(), n = v2.size();
  if(n < m) return findMedianSortedArrays(v2, v1);

  int l = 0, r = m;
  while(l <= r){
      int cut1 = (l+r)/2;
      int cut2 = (m+n+1)/2 - cut1;   //(m+n)/2 - cut1

      int left1 = (cut1 == 0) ? -1e9 : v1[cut1-1]; 
      int right1 = (cut1 == m) ? 1e9 : v1[cut1]; 

      int left2 = (cut2 == 0) ? -1e9 : v2[cut2-1]; 
      int right2 = (cut2 == n) ? 1e9 : v2[cut2]; 

      if(left1 <= right2 && left2 <= right1){
          if((m+n)%2 == 0) return (max(left1, left2)+ min(right1, right2))/2.0;
          else return max(left1, left2);
      }
     else if (left1 > right2) r = cut1-1;      
     else l = cut1+1;                                     
  }
return 0.0;
}


