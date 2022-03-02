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

//author: kunaliescpp
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

void solver(vector<int>& v, int l, int r){
    
    if(l >= r) return;

    int mid = (l+r)/2;
    solver(v, l, mid);
    solver(v, mid+1, r);
    
    vector<int> store;
    int i = l, j = mid+1;
    while(i <= mid && j <= r){
        if(v[i] <= v[j]) store.push_back(v[i++]);
        else store.push_back(v[j++]);
    }
    
    while(i <= mid) store.push_back(v[i++]);
    while(j <= r) store.push_back(v[j++]);
    
    for(int ci = 0; ci < store.size(); ci++){
        v[ci+l] = store[ci];
    }
}

int32_t main() {

    int n; cin >> n;
      
    vector<int>v(n);
    for(int &i: v) cin >> i;
    solver(v, 0, n-1);
    for(int &i: v) cout << i << " ";
  
  return 0;
}


