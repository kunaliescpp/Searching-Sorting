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

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:
1 <= piles.length <= 10^4
piles.length <= h <= 10^9
1 <= piles[i] <= 10^9
*/

  
class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int sp){    // is possible to finish the lunch with given speed
        
        double time = 0;
        for(int i = 0; i < piles.size(); i++){
            time += ceil(piles[i]*1.0/sp);
        }
        
    return time <= h;
    }
    
    //just ok speed of complete the lunch on time
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int sum = 0; int maxi = INT_MIN;
        for(int i : piles){
            maxi = max(maxi , i);
        }
    
        if(h == piles.size()) return maxi;
        
        int start = 0, end = maxi;
        int speed = INT_MAX;
        while(start <= end){
            
            int mid = start + (end-start)/2;
            if(isPossible(piles, h, mid) == true){    //same time taken to eat the lunch but speed is less (found on left half)
                speed = mid;
                end = mid-1;                          // left me check kro, curr se or kam milegi 
            } else {
                start = mid+1;
            }
        }
    return speed;
    }
};





