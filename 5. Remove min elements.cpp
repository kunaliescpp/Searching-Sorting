/*
Problem Link: https://practice.geeksforgeeks.org/problems/remove-minimum-elements4612/1

Remove minimum elements 

Given an unsorted array Arr of size N. Find the minimum number of removals required such that twice of minimum element 
in the array is greater than or equal to the maximum in the array.

Example 1:
Input: N = 9
Arr[] = {4,5,100,9,10,11,12,15,200}
Output: 4
Explanation: In the given array 4 elements 4, 5, 200 and 100 are removed from the array to make the array such that
2*minimum >= max (2*9 > 15).

Example 2:
Input: N = 4
Arr[] = {4,7,5,6}
Output: 0
Explanation: We don't need to remove any element as  4*2 > 7 (Note that min = 4, max = 7).


Constraints:
1 ≤ N ≤ 10^7
1 ≤ Arri ≤ 10^9
*/

int minRemoval(int arr[], int n){

   sort(arr, arr+n);

   int ans = 1e9;
   for(int i = 0; i < n; i++){
    auto it = upper_bound(arr, arr+n, 2*arr[i]);
    int j = it-1-arr;
    ans = min(ans, (i)+(n-1-j));
   }
return ans;
}


