/*
Problem Link: https://leetcode.com/problems/koko-eating-bananas/

Koko Eating Bananas

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will 
come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from
that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30


Constraints:
1 <= piles.length <= 10^4
piles.length <= h <= 10^9
1 <= piles[i] <= 10^9
*/

bool checker(vector<int>& piles, int val, int h){
    int n = piles.size();

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(piles[i] <= val) cnt++;
        else cnt+= ceil((double)piles[i]/val);
    }
return cnt<=h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();

    int ans = 0;
    int l = 1, r = 1e9;
    while(l <= r){
        int mid = (l+r)/2;

        if(checker(piles, mid, h) == 1){
            ans = mid;
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
return ans;
}


