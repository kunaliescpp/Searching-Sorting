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
1 <= arr[i] <= 3*10^4
arr[0] == 1
arr[i] is a prime number for i > 0.
All the numbers of arr are unique and sorted in strictly increasing order.
1 <= k <= arr.length * (arr.length - 1) / 2
*/

vector<int> getFractionsLessThanMid (vector<int>& v, double mid){
    int n = v.size();

    int cnt = 0;
    int j = 1, temp = n-1;
    int p = 0, q = 1;
    for(int i = 0; i <= n-2; i++){
        while(j < n && v[i] > mid * v[j]){          // arr[i]/arr[j] <= mid
            j++; temp--;
        }
        cnt += temp;

        if(j < n && (p*v[j] < q*v[i])){        // p/q < arr[i]/arr[j] -> (near mid = update)
            p = v[i];
            q = v[j];
        }
    }
return {cnt, p, q};
}

vector<int> kthSmallestPrimeFraction(vector<int>& v, int k) {
    int n = v.size();

    double l = 0, r = 1.0;
    while (l <= r){
        double mid = (l+r)/2;

        vector<int>ans = getFractionsLessThanMid(v, mid);
        if(ans[0] < k) l = mid;
        else if (ans[0] > k) r = mid;
        else return {ans[1], ans[2]};                           // return {p, q}
    }
return {};
}


