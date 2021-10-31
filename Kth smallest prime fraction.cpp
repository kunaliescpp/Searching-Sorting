/*
Problem Link: https://leetcode.com/problems/k-th-smallest-prime-fraction/

K-th Smallest Prime Fraction

You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. 
You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i]
and answer[1] == arr[j].

Example 1:
Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are: 1/5, 1/3, 2/5, 1/2, 3/5, and 2/3. The third fraction is 2/5.

Example 2:
Input: arr = [1,7], k = 1
Output: [1,7]
 

Constraints:
2 <= arr.length <= 1000
1 <= arr[i] <= 3 * 10^4
arr[0] == 1
arr[i] is a prime number for i > 0.
All the numbers of arr are unique and sorted in strictly increasing order.
1 <= k <= arr.length * (arr.length - 1) / 2
*/


class Solution {
public:
    // Time complexity : n *log(no. of decimals btw 0 -> 1) = n log(10^9)
    // where no. of decimals = no. of mid taken
    vector<int> getFractionsLessThanMid (vector<int>& arr, int k, int n, double mid){
         
            int cnt = 0;
            int j = 1, temp = n-1-j+1;
            int p = 0, q = 1;
            for(int i = 0; i < n-1; i++){
                
                while(j < n && arr[i] > mid * arr[j]){          // arr[i]/arr[j] <= mid
                    j++; temp--;
                }
                cnt += temp;
            
                if(j < n && (p * arr[j] < q * arr[i]) ){        // p/q < arr[i]/arr[j] -> (near mid = update)
                    p = arr[i];
                    q = arr[j];
                }
            }
    
    return {cnt, p, q};
    }
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n = arr.size();
        double low = 0, high = 1.0;
        while (low < high){
            
            double mid = (low + high)/2;
            
            vector<int> res = getFractionsLessThanMid(arr, k, n, mid);
        
            if(res[0] < k) low = mid;
            else if (res[0] > k) high = mid;
            else return {res[1], res[2]};                           // return {p, q}
        }
    
    return {};
    }
};



