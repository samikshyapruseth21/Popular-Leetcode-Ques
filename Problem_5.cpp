/*
LeetCode Problem: Longest Palindromic Substring
Question: Given a string s, return the longest palindromic substring in s.

A palindrome is a string that reads the same backward as forward.

Example 1:
Input: s = "babad"
Output: "bab" or "aba"

Example 2:
Input: s = "cbbd"
Output: "bb"

Approach: Expand Around Center
1. For each character in the string, treat it as the center of a potential palindrome
2. Expand outward to check for longer palindromes (handles both odd and even lengths)
3. Keep track of the longest palindrome found
4. Time Complexity: O(n²), Space Complexity: O(1)
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;      // Starting index of longest palindrome
        int max_len = 1;     // Length of longest palindrome (minimum is 1)
        
        for (int i = 0; i < s.size(); i++) {
            // Check for odd-length palindromes (center at i)
            int len1 = expandAroundCenter(s, i, i);
            // Check for even-length palindromes (center between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Get the maximum length between odd and even length palindromes
            int current_max = max(len1, len2);
            
            // Update longest palindrome if current is longer
            if (current_max > max_len) {
                max_len = current_max;
                // Calculate starting index (center - half length)
                start = i - (max_len - 1) / 2;
            }
        }
        
        // Return the substring from start to start+max_len
        return s.substr(start, max_len);
    }
    
private:
    // Helper function to expand around center and return palindrome length
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;   // Expand left
            right++;  // Expand right
        }
        // Return length of palindrome (right - left - 1)
        return right - left - 1;
    }
};