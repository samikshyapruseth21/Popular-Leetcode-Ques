/*
LeetCode Problem: Integer to Roman
Question: Given an integer, convert it to a roman numeral.

Roman numerals are represented by seven different symbols:
I (1), V (5), X (10), L (50), C (100), D (500), M (1000)

There are six special cases where subtraction is used:
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

Approach: Greedy Algorithm
1. Create a table of value-symbol pairs in descending order, including special cases
2. Iterate through the table, repeatedly subtracting the largest possible values
3. Append the corresponding symbols to the result string
4. Continue until the number is reduced to zero
*/

class Solution {
public:
    string intToRoman(int num) {
        // Predefined value-symbol pairs in descending order
        // Includes both standard symbols and special cases
        const vector<pair<int, string>> valueSymbols{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};

        string result;

        // Process each value-symbol pair from largest to smallest
        for (const auto& [value, symbol] : valueSymbols) {
            // Early exit if we've completely converted the number
            if (num == 0) break;

            // Repeatedly subtract the current value while possible
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }

        return result;        
    }
};