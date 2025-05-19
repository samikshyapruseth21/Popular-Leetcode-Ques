/*
LeetCode Problem: Regular Expression Matching
Question: Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*'.
- '.' Matches any single character.
- '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, "a*" matches "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Approach: Dynamic Programming
1. Create a DP table where dp[i][j] represents whether s[0..i-1] matches p[0..j-1]
2. Handle three cases for pattern characters:
   a. If p[j-1] is not '*': simple character match
   b. If p[j-1] is '*': either ignore the pattern or match one/more characters
3. Base case: empty pattern matches empty string
4. Time Complexity: O(m*n), Space Complexity: O(m*n)
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));
        
        // Base case: empty pattern matches empty string
        dp[0][0] = true;
        
        // Handle patterns like a*, a*b*, a*b*c* etc. that can match empty string
        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j-1] == '*') {
                    // Case 1: Treat 'a*' as empty (ignore the pattern)
                    bool ignorePattern = dp[i][j-2];
                    
                    // Case 2: Use 'a*' to match current character
                    bool matchChar = (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];
                    
                    dp[i][j] = ignorePattern || matchChar;
                }
                else {
                    // Simple character match (exact or '.')
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        
        return dp[n][m];
    }
};