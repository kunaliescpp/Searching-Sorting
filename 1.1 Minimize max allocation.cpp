/*
Problem Link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#

Minimize maximum allocation of pages 

You are given N number of books. Every ith book has Ai number of pages.

You have to allocate contagious books to M number of students. There can be many ways or permutations to do so. In each permutation, one 
of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular
permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print
this minimum value.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better 
understanding).

Example 1:
Input: N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in following ways:
Maximum Pages allocation = 191 [{12} and {34, 67, 90}] 
Maximum Pages allocation = 157 [{12, 34} and {67, 90}] 
Maximum Pages allocation = 113 [{12, 34, 67} and {90}] 
Therefore, the min in all these cases is 113, which is selected as the output.


Constraints:
1 <= N <= 10^5
1 <= A [ i ] <= 10^6
1 <= M <= 10^5
*/

bool checker(int v[], int val, int n, int m){
    int sum = 0;
    int cut = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > val) return 0;

        if(sum + v[i] > val){
            cut++;
            sum = v[i];
        } else{
            sum += v[i];
        }
    }

return (cut <= m-1);
}

// minimize [max number of pages allocate to student A]
int findPages(int arr[], int n, int m){
    int l = 1, r = 1e11;
    int ans = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(checker(arr, mid, n, m) == 1){
            ans = mid;
            r = mid-1;
        } else{
            l = mid+1;
        }
    }

return ans;
}


