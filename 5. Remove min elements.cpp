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

class Solution{
public:

    int first_Greatest(int arr[], int si, int ei, int target){
      
        while(si <= ei) {
            int mid = (si+ei)/2;
          
            if (arr[mid] <= target){
                si = mid + 1;
            }
            
            else if (arr[mid] > target){
                ei = mid - 1;
            }
        }
        // cout<< ei + 1 << "";
    return ei + 1;
    }
   
    // 2*min element >= max element
	int minRemoval(int arr[], int n){
	    
	   int res = INT_MAX;
	   sort(arr, arr+n);
	   for(int i = 0; i < n; i++){
	       int removals = first_Greatest(arr, i+1, n-1, 2*arr[i]);
	       //int x = i+n-removals;
	       //cout << x;
	       res = min(res, n-removals+i);
	   }
	return res;
	}
};


