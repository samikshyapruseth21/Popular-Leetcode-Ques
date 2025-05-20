/*
LeetCode Problem: Roman to Integer
Question: Convert a Roman numeral string to an integer.

Roman numerals are represented by seven symbols:
I (1), V (5), X (10), L (50), C (100), D (500), M (1000)

Special cases where subtraction is used:
IV (4), IX (9), XL (40), XC (90), CD (400), CM (900)

Approach:
1. Create a mapping of Roman symbols to their values
2. Iterate through the string, comparing current and next symbols
3. If current symbol is smaller than next (subtraction case), subtract its value
4. Otherwise, add its value
5. Finally, add the last symbol's value
6. Time Complexity: O(n), Space Complexity: O(1)
*/

class Solution {
public:
    int romanToInt(string s) {
        // Map to store Roman numeral values
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;

        // Iterate through all characters except the last one
        for (int i = 0; i < s.size() - 1; i++) {
            // Check for subtraction cases (current symbol < next symbol)
            if (romanValues[s[i]] < romanValues[s[i + 1]]) {
                result -= romanValues[s[i]];  // Subtract current value
            } else {
                result += romanValues[s[i]];  // Add current value
            }
        }

        // Always add the last symbol's value
        return result + romanValues[s.back()];        
    }
};