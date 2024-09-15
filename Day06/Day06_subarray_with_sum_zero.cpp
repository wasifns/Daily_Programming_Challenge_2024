#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> subarraysWithSumZero(int arr[], int n) {
    
    vector<pair<int, int>> result;
    
    // Map to store the sum and its indices
    unordered_map<int, vector<int>> sumIndexMap;
    
    int check_sum = 0;
    
    // Iterate through the array
    for (int i = 0; i < n; i++) {
        check_sum += arr[i];
        
        // the sum is 0
        if (check_sum == 0) {
            result.push_back({0, i});
        }
        
        // If check_sum has occured before
        if (sumIndexMap.find(check_sum) != sumIndexMap.end()) {
            for (auto index : sumIndexMap[check_sum]) {
                result.push_back({index + 1, i});
            }
        }
        
        // Store the current sum and its index
        sumIndexMap[check_sum].push_back(i);
    }
    
    return result;
}

int main() {
    int arr[] = {1, 2, -3, 3, -1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<pair<int, int>> subarrays = subarraysWithSumZero(arr, n);

    if (subarrays.empty()) {
        cout << "No subarrays with sum 0 found." << endl;
    } else {
        cout << "Subarrays with sum 0:" << endl;
        for (auto &subarray : subarrays) {
            cout << "(" << subarray.first << ", " << subarray.second << ")" << endl;
        }
    }

    return 0;
}
