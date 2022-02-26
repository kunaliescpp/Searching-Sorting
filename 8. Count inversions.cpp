/*
Problem Link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

Count Inversions 

Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is 
already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 
Example 1:
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Example 2:
Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Example 3:
Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.


Constraints:
1 ≤ N ≤ 5*10^5
1 ≤ arr[i] ≤ 10^18
*/
    
long long countandMerge(long long arr[], int start, int mid, int end){
// Time: O(n),  Aux space : O(n)

    //Setting up auxiliary arrays
    long long n1 = mid - start + 1; 
    long long n2 = end - mid;
    long long left[n1], right[n2];
    
    for(long long i = 0; i < n1; i++) left[i] = arr[start + i];
    for(long long i = 0; i < n2; i++) right[i] = arr[mid + 1 + i];
   
   //Basic merge logic
   long long res = 0;
   long long  i = 0, j = 0, k = start;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++; k++;
        } else {
            arr[k] = right[j];
            res = res + (n1-i);            //left arr me curr pointer (i)->end tak no. of elements
            k++; j++;
        }
    }
    
    while(i < n1){
       arr[k] = left[i];
       k++; i++;
    }
    
    while(j < n2){
       arr[k] = right[j];
       k++; j++;
    }
return res;
}
   
long long int invCount(long long arr[], long long start, long long end){
    
    long long res = 0;
    if(start >= end) return 0;
        
    int mid = start + (end-start)/2;
    
    res += invCount(arr, start, mid);
    res += invCount(arr, mid + 1, end);
    res += countandMerge(arr, start, mid , end);

return res;
}

long long int inversionCount(long long arr[], long long n){
    // start and end is not given in input, so we need another function
    invCount(arr, 0, n-1);
}


