/*
LeetCode Problem: Median of Two Sorted Arrays
Question: Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Approach:
1. Merge the two sorted arrays into a single sorted array.
2. Use two pointers to efficiently merge the arrays by comparing elements from both arrays.
3. After merging, find the median:
   - If the merged array has odd length, the median is the middle element.
   - If even length, the median is the average of the two middle elements.
Note: This approach has O(m+n) time complexity which is acceptable for many cases, 
though the optimal solution would use binary search for O(log(min(m,n))) complexity.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Create a vector to store the merged sorted array
        vector<int> merged;
        
        // Initialize pointers for both arrays and get their sizes
        int a = nums1.size();
        int b = nums2.size();
        int i = 0, j = 0;  // i for nums1, j for nums2

        // Merge the two sorted arrays
        while(i < a && j < b) {
            // Compare current elements of both arrays
            if(nums1[i] > nums2[j]) {
                merged.push_back(nums2[j]);
                j++;
            }
            else {
                merged.push_back(nums1[i]);
                i++;
            }
        }

        // Add remaining elements from nums1 if any
        while(i < a) {
            merged.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2 if any
        while(j < b) {
            merged.push_back(nums2[j]);
            j++;
        }

        // Calculate median based on merged array size
        int n = merged.size();
        if(n % 2 == 1) {
            // Odd length: return middle element
            return merged[n/2];
        }
        else {
            // Even length: return average of two middle elements
            // Cast to double for precise division
            return (double)(merged[n/2 - 1] + merged[n/2]) / 2.0;
        }
    }
};
