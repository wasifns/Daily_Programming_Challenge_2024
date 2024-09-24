#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string expandAroundCenter(const string &s, int left, int right) {
        
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";

        string longestPalindrome = "";

        for (int i = 0; i < s.length(); i++) {
            // Check for odd-length palindrome (center at i)
            string oddPalindrome = expandAroundCenter(s, i, i);
            // Check for even-length palindrome (center between i and i+1)
            string evenPalindrome = expandAroundCenter(s, i, i + 1);

            // Update longest palindrome if a longer one is found
            if (oddPalindrome.length() > longestPalindrome.length())
                longestPalindrome = oddPalindrome;
            if (evenPalindrome.length() > longestPalindrome.length())
                longestPalindrome = evenPalindrome;
        }

        return longestPalindrome;
    }
};

int main() {
    Solution solution;
    string s = "babad";
    cout << "Longest Palindromic Substring: " << solution.longestPalindrome(s) << endl;
    return 0;
}
