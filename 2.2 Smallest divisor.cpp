/*
Problem Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

Find the Smallest Divisor Given a Threshold

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, 
and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
It is guaranteed that there will be an answer.

Example 1:
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor 
is 5 the sum will be 5 (1+1+1+2). 

Example 2:
Input: nums = [44,22,33,11,1], threshold = 5
Output: 44

Example 3:
Input: nums = [21212,10101,12121], threshold = 1000000
Output: 1


Constraints:
1 <= nums.length <= 5 * 10^4
1 <= nums[i] <= 10^6
nums.length <= threshold <= 10^6
*/
    
bool checker(vector<int>& nums, int threshold, int val){
    int n = nums.size();

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum+= ceil(nums[i]*1.0/val);
    }

return (sum <= threshold);
}

int smallestDivisor(vector<int>& nums, int threshold) {

    int ans = 0;
    int l = 1, r = 1e9;
    while(l <= r){
        int mid = (l+r)/2;

        if(checker(nums, threshold, mid) == 1){
            ans = mid;
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
return ans;
}


