/*
LeetCode Problem: String to Integer (atoi)
Question: Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm:
1. Read and ignore leading whitespace
2. Check for '+' or '-' to determine sign
3. Read digits until non-digit or end of string
4. Convert digits to integer, handling overflow
5. Return final result with sign

Example 1:
Input: s = "42"
Output: 42

Example 2:
Input: s = "   -42"
Output: -42

Example 3:
Input: s = "4193 with words"
Output: 4193

Example 4:
Input: s = "words and 987"
Output: 0
*/

#include <iostream>
#include <string>
#include <climits> // For INT_MAX and INT_MIN
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;          // Current position in string
        int sign = 1;       // 1 for positive, -1 for negative
        long result = 0;    // Using long to detect overflow before casting to int

        // 1. Skip leading whitespace
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        if (i == s.size