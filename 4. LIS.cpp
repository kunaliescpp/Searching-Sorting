/*
Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/

Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the 
remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
 
 
Constraints:
1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4
*/

int lengthOfLIS(vector<int>& v) {
    int n = v.size();

    vector<int> lis;
    lis.push_back(v[0]);
    for(int i = 1; i < n; i++){
        if(v[i] > lis[lis.size()-1]){
            lis.push_back(v[i]);
        } else{
            int m = lis.size();
            int ans = 0;
            int l = 0, r = m-1;
            while(l <= r){
                int mid = (l+r)/2;

                if(v[i] <= lis[mid]){
                    ans = mid;
                    r = mid-1;
                } else{
                    l = mid+1;
                }
            }
            lis[ans] = v[i];
        }
    }
return (int)lis.size();   
}


