#include <iostream>
using namespace std;

void findMissingNumber(int* arr, int sum, int arr_sum, int n){
    //using number sum approach
    //sum of n number
    for(int i = 0; i <= n; i++){
        sum += i;
    }
    //sum of elements of array
    for(int i = 0; i < 4; i++){
        arr_sum += arr[i];
    }

    int missing_number = sum - arr_sum;
    cout << "Missing number is " << missing_number << endl;


  
};

int main(){
    int arr[] = {1,2,3,5};
    int n = 5;
    int sum = 0;
    int arr_sum = 0;
    int missing_number;
    findMissingNumber(arr,sum, arr_sum, n);
}