/*
LeetCode Problem: 3Sum
Question: Given an integer array nums, return all unique triplets [nums[i], nums[j], nums[k]] 
such that i != j != k and nums[i] + nums[j] + nums[k] == 0.

Example:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Approach: Two Pointers with Sorting and Deduplication
1. Sort the array to enable two-pointer technique
2. Use a set to store unique triplets
3. For each element nums[i], use two pointers (j, k) to find pairs that sum to -nums[i]
4. Skip duplicates to avoid redundant checks
5. Convert set to vector before returning
6. Time Complexity: O(n²) (dominated by the nested loops)
7. Space Complexity: O(n) (for storing results and set)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> uniqueTriplets;  // Stores unique triplets
        vector<vector<int>> result;

        // Edge case: array too small
        if (nums.size() < 3) return result;

        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicate elements for i
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;  // Left pointer
            int k = nums.size() - 1;  // Right pointer

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == target) {
                    // Found a valid triplet
                    uniqueTriplets.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicates for j and k
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                } 
                else if (sum < target) {
                    j++;  // Need larger sum
                } 
                else {
                    k--;  // Need smaller sum
                }
            }
        }

        // Convert set to vector
        for (const auto& triplet : uniqueTriplets) {
            result.push_back(triplet);
        }

        return result;
    }
};