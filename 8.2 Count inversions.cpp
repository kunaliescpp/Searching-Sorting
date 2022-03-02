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
*/
    
//author: kunaliescpp
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

int solver(vector<int>& v, int l, int r){
    
    if(l >= r) return 0;

    int mid = (l+r)/2;
    int left_cnt = solver(v, l, mid);
    int right_cnt = solver(v, mid+1, r);
    
    vector<int> store;
    int i = l, j = mid+1;
    int cnt = 0;
    while(i <= mid && j <= r){
        if(v[i] <= v[j]){
            store.push_back(v[i++]);
        } else{
            store.push_back(v[j++]);
            cnt+= (mid-i+1);
        } 
    }
    
    while(i <= mid) store.push_back(v[i++]);
    while(j <= r) store.push_back(v[j++]);
    
    for(int ci = 0; ci < store.size(); ci++){
        v[ci+l] = store[ci];
    }
return (left_cnt + right_cnt + cnt);
}

int32_t main() {

    int n; cin >> n;
      
    vector<int>v(n);
    for(int &i: v) cin >> i;
    
    int cnt = solver(v, 0, n-1);
    cout << "Inversion count: " << cnt << endl;
    for(int &i: v) cout << i << " ";
  return 0;
}


