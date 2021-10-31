/*
Problem Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

Capacity To Ship Packages Within D Days

A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt 
(in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Example 1:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5),
(1, 6, 7), (8), (9), (10) is not allowed.

Example 2:
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

Example 3:
Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
 

Constraints:
1 <= days <= weights.length <= 5 * 10^4
1 <= weights[i] <= 500
*/


class Solution {
public:
    // Similar as 'Allocate minimum no. of pages on GFG'
    bool isFeasible(vector<int> arr, int n, int m, int number){
        
        int cnt = 1, Sum = 0;                               // error corrected: cnt == 0
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
    
    int shipWithinDays(vector<int>& weights, int days) {
        
      int n = weights.size();
      // result is must be in btw [max_element, arrSum]
      int sum = 0, maxi = 0;
       for(int i = 0; i < n; i++){
           sum += weights[i];
           maxi = max(maxi, weights[i]);
       }
      
      int start = maxi, end = sum; 
      int ans = 0;
      while(start <= end){
          
          int mid = start +  (end - start)/2;
          
          // if fesible, go to the left half
          if(isFeasible(weights, n, days, mid) == true){
              ans = mid;
              end = mid-1;
          }
          //else go to the right half
          else start = mid + 1; 
      }
      
    return ans;  
    }
};
   



