/*
Problem Link: https://practice.geeksforgeeks.org/problems/merge-sort/1

Merge Sort 

Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.

Example 1:
Input: N = 5 , arr[] = {4 1 3 9 7}
Output: 1 3 4 7 9

Example 2:
Input: N = 10, arr[] = {10 9 8 7 6 5 4 3 2 1}
Output: 1 2 3 4 5 6 7 8 9 10

Constraints:
1 <= N <= 10^5
1 <= arr[i] <= 10^3
*/


class Solution{
  // Time complexity : O(n logn), where log n is no. of levels of rec. calls i.e. log2n + 1
   // Aux space : O(n)
    
    public:
    void merge(int arr[], int start, int mid, int end){
        
    // Time: O(n),  Aux space : O(n)
    
        //Setting up auxiliary arrays
        int n1 = mid - start + 1; 
        int n2 = end - mid;
        int left[n1], right[n2];
        
        for(int i = 0; i < n1; i++) left[i] = arr[start + i];
        for(int i = 0; i < n2; i++) right[i] = arr[mid + 1 + i];
       
       //Basic merge logic
       int i = 0, j = 0, k = start;
        while(i < n1 && j < n2){
            if(left[i] <= right[j]){
                arr[k] = left[i];
                i++; k++;
            } else {
                arr[k] = right[j];
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
    }
    
    void mergeSort(int arr[], int start, int end){
        
        if(start >= end) return;
            
        int mid = start + (end-start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid , end);

    }
};




