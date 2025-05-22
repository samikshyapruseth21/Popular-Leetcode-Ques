/*
LeetCode Problem: 3Sum Closest
Question: Given an integer array nums and a target value, find three integers 
in nums such that the sum is closest to target. Return the sum of the triplet.

Example:
Input: nums = [-1,2,1,-4], target = 1
Output: 2 (-1 + 2 + 1 = 2 is closest to target)

Approach: Two Pointers with Sorting
1. Sort the array to enable two-pointer technique
2. Initialize closest sum with first possible triplet
3. For each element nums[i], use two pointers (left, right) to find best pair:
   a. Calculate current sum of triplet
   b. Update closest sum if current sum is closer to target
   c. Move pointers based on comparison with target
4. Early return if exact match found
5. Time Complexity: O(n²) (sorting is O(n log n))
6. Space Complexity: O(1) (excluding sort space)
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array to enable two-pointer approach
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Initialize with first possible triplet sum
        int closestSum = nums[0] + nums[1] + nums[2];
        
        // Iterate through each element as potential first element of triplet
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates to avoid redundant checks
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i + 1;    // Pointer to second element
            int right = n - 1;    // Pointer to third element
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // Update closest sum if current sum is closer to target
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // Move pointers based on comparison with target
                if (currentSum < target) {
                    left++;  // Need larger sum
                } else if (currentSum > target) {
                    right--; // Need smaller sum
                } else {
                    return currentSum;  // Exact match found
                }
            }
        }
        
        return closestSum;
    }
};