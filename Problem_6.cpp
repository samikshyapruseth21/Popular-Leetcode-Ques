/*
LeetCode Problem: ZigZag Conversion
Question: The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Given a string s and number of rows numRows, return the zigzag conversion of the string.

Example:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Approach:
1. Create an array of strings, one for each row.
2. Use a pointer to track the current row and a direction flag.
3. Iterate through the string, placing each character in the appropriate row.
4. Change direction when reaching the top or bottom row.
5. Finally, concatenate all rows to get the result.
*/

class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if only one row or empty string, return as is
        if(numRows <= 1) return s;

        // Create a vector of strings to hold characters for each row
        vector<string> rows(numRows, ""); 

        // j: current row index, dir: direction (1 for down, -1 for up)
        int j = 0, dir = -1;

        for(int i = 0; i < s.length(); i++) {
            // Change direction when reaching top or bottom row
            if(j == numRows - 1 || j == 0) {
                dir *= (-1); 
            }
            
            // Add current character to the current row
            rows[j] += s[i];

            // Move to next row based on direction
            if(dir == 1) {
                j++;  // Moving down
            }
            else {
                j--;  // Moving up
            }
        }

        // Concatenate all rows to form the result
        string res;
        for(auto &row : rows) {
            res += row; 
        }

        return res;
    }
};
