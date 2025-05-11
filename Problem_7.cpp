/*
LeetCode Problem: Reverse Integer
Question: Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-2³¹, 2³¹ - 1], 
then return 0.

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Approach:
1. Initialize a variable to store the reversed integer.
2. While the original number is not zero:
   a) Extract the last digit using modulo operation.
   b) Check for overflow/underflow before updating the result.
   c) Update the reversed number by multiplying by 10 and adding the digit.
   d) Remove the last digit from the original number.
3. Return the reversed number or 0 if overflow occurred.
*/

class Solution {
public:
    int reverse(int x) {
        int reversed = 0;  // Stores the reversed number
        
        while(x != 0) {
            int digit = x % 10;  // Extract the last digit
            
            // Check for overflow/underflow before updating reversed
            // INT_MAX = 2147483647 (2³¹ - 1), INT_MIN = -2147483648 (-2³¹)
            if(reversed > INT_MAX/10 || reversed < INT_MIN/10) {
                return 0;
            }
            
            // Update the reversed number
            reversed = (reversed * 10) + digit;
            
            // Remove the last digit from original number
            x /= 10;
        }
        
        return reversed;
    }
};