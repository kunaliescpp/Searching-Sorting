/*
Problem Link: https://leetcode.com/problems/split-array-largest-sum/

Split Array Largest Sum

Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty 
continuous subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.

Example 1:
Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays. The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

Example 2:
Input: nums = [1,2,3,4,5], m = 2
Output: 9

Example 3:
Input: nums = [1,4,4], m = 3
Output: 4
 
Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 10^6
1 <= m <= min(50, nums.length)
*/

bool checker(vector<int>& v, int maxi, int m){
    int n = v.size();

    int sum = 0;
    int cut = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > maxi) return 0;

        if(sum + v[i] > maxi){
            cut++;
            sum = v[i];
        } else{
            sum += v[i];
        }
    }    
return (cut <= m-1);
}

int splitArray(vector<int>& v, int m) {
    int n = v.size();

    int l = 0, r = 1e9;
    int ans = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(checker(v, mid, m) == 1){
            ans = mid;
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
return ans;
}


