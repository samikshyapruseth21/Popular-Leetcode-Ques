/*
LeetCode Problem: Integer to Roman
Question: Convert an integer to a Roman numeral.

Roman numerals are formed by combining letters:
I (1), V (5), X (10), L (50), C (100), D (500), M (1000)

Special cases using subtraction principle:
IV (4), IX (9), XL (40), XC (90), CD (400), CM (900)

Example 1:
Input: num = 3
Output: "III"

Example 2:
Input: num = 58
Output: "LVIII" (L = 50, V = 5, III = 3)

Example 3:
Input: num = 1994
Output: "MCMXCIV" (M = 1000, CM = 900, XC = 90, IV = 4)

Approach: Digit-by-Digit Conversion
1. Predefine arrays for each digit place (thousands, hundreds, tens, ones)
2. Extract each digit from the input number
3. Concatenate the corresponding Roman numeral segments
4. Time Complexity: O(1) - fixed number of operations
5. Space Complexity: O(1) - fixed size arrays
*/

class Solution {
public:
    string intToRoman(int num) {
        // Arrays mapping digit values to Roman numeral segments
        string thousands[] = {"", "M", "MM", "MMM"};  // 0-3000 (0, 1000, 2000, 3000)
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};  // 0-900
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};  // 0-90
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};  // 0-9
        
        // Break down the number into digits and concatenate the corresponding Roman segments
        return thousands[num / 1000] +          // Thousands place
               hundreds[(num % 1000) / 100] +   // Hundreds place
               tens[(num % 100) / 10] +         // Tens place
               ones[num % 10];                  // Ones place
    }
};