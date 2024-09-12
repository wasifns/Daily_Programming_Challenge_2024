#include <iostream>
using namespace std;

int findDuplicate(int* arr, int n){
    //edge case handling
    if( n == 1 && arr[0] == arr [1]){
        std::cout << "Both elements are same" << endl;

    }


    //using slow and fast pointer approach
    int slow = arr[0];
    int fast = arr[0];
    
    //incrementing slow pointer by 1 and fast by 2 until they meet
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);

    //when both pointers meet reset one pointer and increment both by 1 until they meet
    slow = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }


    return fast;


};

int main(){

    int arr[] = {1,1};
    int n = sizeof(arr)/sizeof(arr[0]) - 1;
    cout << "The duplicate number in the array: " << findDuplicate(arr ,n) << endl;
    return 0;
}