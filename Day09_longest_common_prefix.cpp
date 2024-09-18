#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    // for an empty string
    if (strs.empty()) return "";

    // Start with the first string 
    string prefix = strs[0];

    // Compare the prefix with each string in the list
    for (int i = 1; i < strs.size(); i++) {
        // reduce the prefix until the current string starts with the prefix
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            // If no common prefix, return an empty string
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;  
    return 0;
}