#include <iostream>
#include <algorithm>
using namespace std;

string reverseStringWord(string str) {
    // Reverse the whole string
    reverse(str.begin(), str.end());

    int i = 0;
    int l = 0, r = 0;
    int n = str.length();

    // Reverse each word in the reversed string (words are separated by '.')
    while (i < n) {
        // Traverse the word (until a dot is found or end of string)
        while (i < n && str[i] != '.') {
            str[r++] = str[i++];
        }

        // Reverse the word that was found 
        if (l < r) {
            reverse(str.begin() + l, str.begin() + r);
            l = r + 1;  // Move the left pointer to the  after the dot
        }

        // Skip the dot and add it back
        if (i < n && str[i] == '.') {
            str[r++] = '.';
            i++; 
        }
    }

    return str;
}

int main() {
    string input = "the.sky.is.blue";
    cout << "Original string: \"" << input << "\"" << endl;
    string output = reverseStringWords(input);
    cout << "Reversed words of the string: \"" << output << "\"" << endl;
    return 0;
}