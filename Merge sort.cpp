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

#include <iostream>
using namespace std;

// Merge sort
void merge(vector<int>& v, int si, int ei){
    if(si >= ei) return;
    
    int mid = (si + ei)/2;
    merge(v, si, mid);
    merge(v, mid+1, ei);

    int i = si, j = mid+1;
    vector<int> ans;
    while(i <= mid && j <= ei){
        if(v[i] > v[j]) ans.push_back(v[j++]);
        else ans.push_back(v[i++]);
    }
    
    while(i <= mid) ans.push_back(v[i++]);
    while(j <= end) ans.push_back(v[j++]);
    
    for(int i = si; i <= ei; i++){
        v[i] = ans[i-si];
    }
}

int main() {
	
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int &i : v){
	    cin >> i;
	}
	
	merge(v, 0, n-1);
	
	for(int i = 0; i < n; i++){
	    cout << v[i] << " ";
	}

return 0;
}


