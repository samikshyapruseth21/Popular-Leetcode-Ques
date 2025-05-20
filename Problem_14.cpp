/*
LeetCode Problem: Longest Common Prefix
Question: Find the longest common prefix string among an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""

Approach: Vertical Scanning with Early Termination
1. Take the first string as initial prefix candidate
2. Compare with each subsequent string:
   a. Reduce prefix length until it matches the beginning of current string
   b. Early return if prefix becomes empty
3. Time Complexity: O(S) where S is total characters in all strings
4. Space Complexity: O(1) additional space
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Handle empty input case
        if (strs.empty()) return "";

        // Initialize with first string as prefix candidate
        string prefix = strs[0];
        int prefixLength = prefix.length();

        // Compare with each string in the array
        for (int i = 1; i < strs.size(); i++) {
            const string& currentStr = strs[i];
            
            // Reduce prefix until it matches current string's beginning
            while (prefixLength > currentStr.length() || 
                   prefix != currentStr.substr(0, prefixLength)) {
                prefixLength--;
                
                // Early termination if no common prefix
                if (prefixLength == 0) {
                    return "";
                }
                
                // Update prefix to new shorter version
                prefix = prefix.substr(0, prefixLength);
            }
        }

        return prefix;
    }
};