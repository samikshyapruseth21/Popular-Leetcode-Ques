/*
LeetCode Problem: Longest Substring Without Repeating Characters
Question: Given a string s, find the length of the longest substring without repeating characters.
Example:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Approach:
1. We use a sliding window technique with two pointers (i and j) to represent the current window.
2. A frequency map (vector) is used to keep track of characters in the current window.
3. As we iterate through the string with pointer i, we increment the count of the current character.
4. If a character's count exceeds 1, it means we have a duplicate in the current window.
5. We then move the left pointer (j) forward, decrementing counts, until all characters in the window are unique again.
6. We keep track of the maximum window size encountered during this process.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Frequency map to store character counts (ASCII has 256 characters)
        vector<int> mp(256, 0);
        int mx = 0;       // Stores the maximum length found so far
        int j = 0;         // Left pointer of the sliding window

        // Iterate through the string with right pointer i
        for(int i = 0; i < s.length(); i++) {
            // Increment the count of the current character
            mp[s[i]]++;
            
            // If current character count > 1, we have a duplicate
            while(mp[s[i]] > 1) {
                // Move left pointer forward, decrementing counts
                mp[s[j]]--;
                j++;
            }
            
            // Update maximum length if current window is larger
            mx = max(mx, i - j + 1);
        }
        
        return mx;
    }
};
